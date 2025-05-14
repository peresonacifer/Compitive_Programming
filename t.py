import tkinter as tk
import tkinter.messagebox
import tkinter.font as tkFont
import tkinter.simpledialog
import random
import textwrap
import json
import sys
import os

# --- Game Settings ---
QUESTIONS_FILENAME = "questions.json"

# --- Function to Load Questions ---
def load_questions_from_json(filename):
    try:
        # Ensure we are looking relative to the script's directory
        script_dir = os.path.dirname(os.path.abspath(__file__))
        full_path = os.path.join(script_dir, filename)
        with open(full_path, 'r', encoding='utf-8') as f:
            questions = json.load(f)
            if not isinstance(questions, list):
                print(f"Error: Content in {filename} is not a valid JSON list.")
                return None
            return questions
    except FileNotFoundError:
        print(f"Error: Questions file '{filename}' not found at '{full_path}'.")
        tkinter.messagebox.showerror("錯誤", f"找不到題庫檔案：{filename}\n請確定檔案存在於程式旁邊。")
        return None
    except json.JSONDecodeError as e:
        print(f"Error decoding JSON from {filename}: {e}")
        tkinter.messagebox.showerror("錯誤", f"題庫檔案 {filename} 格式錯誤 (非有效 JSON)。\n錯誤訊息: {e}")
        return None
    except Exception as e:
        print(f"An unexpected error occurred loading questions: {e}")
        tkinter.messagebox.showerror("錯誤", f"讀取題庫時發生未知錯誤: {e}")
        return None

# --- Load questions at the start ---
FLAT_QUESTION_BANK = load_questions_from_json(QUESTIONS_FILENAME)

if FLAT_QUESTION_BANK is None:
    print("Exiting due to question loading failure.")
    sys.exit(1)

TOTAL_QUESTIONS_AVAILABLE = len(FLAT_QUESTION_BANK)

# --- GUI Setup (Colors, Window, Fonts - unchanged) ---
BG_COLOR = "#F5F5DC"
TEXT_COLOR = "#3A3B3C"
CORRECT_COLOR = "#28A745"
WRONG_COLOR = "#DC3545"
DEFAULT_BTN_BG = "#E0E0E0"
DEFAULT_BTN_FG = TEXT_COLOR
DEFAULT_BTN_ACTIVE_BG = "#B0BEC5"
CORRECT_HIGHLIGHT_COLOR = "#90EE90"

window = tk.Tk()
window.title("知識問答挑戰")
window.geometry("650x600") # May need adjustment depending on wrapped text height
window.configure(bg=BG_COLOR)

font_title = tkFont.Font(family="Segoe UI", size=16, weight="bold")
font_question = tkFont.Font(family="Segoe UI", size=14)
font_options = tkFont.Font(family="Segoe UI", size=12)
font_status = tkFont.Font(family="Segoe UI", size=12, weight="bold")
font_button = tkFont.Font(family="Segoe UI", size=12)
font_hint = tkFont.Font(family="Segoe UI", size=10, slant="italic")
font_review = tkFont.Font(family="Segoe UI", size=11)

# --- Game State Variables (unchanged) ---
target_questions = 0
questions_answered = 0
current_question_data = None
player_score = 0
wrong_answer_count = 0
round_question_indices = []
current_question_index_in_round = 0
wrong_answers_list = []
game_in_progress = False
buttons_enabled = False

# --- GUI Elements (unchanged structure, label text updated) ---
start_frame = tk.Frame(window, bg=BG_COLOR)
tk.Label(start_frame, text="🧠 知識問答挑戰 🧠", font=font_title, bg=BG_COLOR, fg=TEXT_COLOR).pack(pady=20)
tk.Label(start_frame, text=f"題庫中共有 {TOTAL_QUESTIONS_AVAILABLE} 道題目。", font=font_options, bg=BG_COLOR, fg=TEXT_COLOR).pack(pady=5)
tk.Label(start_frame, text="你想挑戰幾題？ (按 Enter 確認)", font=font_options, bg=BG_COLOR, fg=TEXT_COLOR).pack(pady=10)
num_questions_entry = tk.Entry(start_frame, font=font_options, width=10, justify=tk.CENTER)
num_questions_entry.pack(pady=5)
start_game_button = tk.Button(start_frame, text="開始挑戰", font=font_button, command=lambda: setup_game())
start_game_button.pack(pady=20)

game_frame = tk.Frame(window, bg=BG_COLOR)
status_frame = tk.Frame(game_frame, bg=BG_COLOR)
status_frame.pack(pady=10, fill=tk.X)
score_label = tk.Label(status_frame, text="分數: 0", font=font_status, bg=BG_COLOR, fg=TEXT_COLOR)
score_label.pack(side=tk.LEFT, padx=20)
question_progress_label = tk.Label(status_frame, text="進度: 0/0", font=font_status, bg=BG_COLOR, fg=TEXT_COLOR)
question_progress_label.pack(side=tk.LEFT, expand=True)
wrong_count_label = tk.Label(status_frame, text="錯誤: 0 ❌", font=font_status, bg=BG_COLOR, fg=WRONG_COLOR)
wrong_count_label.pack(side=tk.RIGHT, padx=20)
question_label = tk.Label(game_frame, text="", font=font_question, bg=BG_COLOR, fg=TEXT_COLOR, justify=tk.LEFT, wraplength=600, height=4)
question_label.pack(pady=15, padx=20, fill=tk.X)
options_frame = tk.Frame(game_frame, bg=BG_COLOR)
options_frame.pack(pady=10, fill=tk.BOTH, expand=True)
feedback_label = tk.Label(game_frame, text="", font=font_status, bg=BG_COLOR)
feedback_label.pack(pady=5)
key_hint_label = tk.Label(game_frame, text="提示: 你也可以使用鍵盤數字 1-5 作答", font=font_hint, bg=BG_COLOR, fg=TEXT_COLOR)
control_frame = tk.Frame(game_frame, bg=BG_COLOR)
control_frame.pack(pady=15, fill=tk.X)
restart_button = tk.Button(control_frame, text="重新開始", font=font_button, command=lambda: show_start_screen())
review_button = tk.Button(control_frame, text="複習錯題", font=font_button, command=lambda: show_review_window())

answer_buttons = []
button_option_map = {}

# --- Game Functions ---

def handle_start_enter(event):
    if start_frame.winfo_ismapped(): setup_game()

def update_status_display():
    score_label.config(text=f"分數: {player_score}")
    progress_num = current_question_index_in_round
    question_progress_label.config(text=f"進度: {progress_num}/{target_questions}")
    wrong_count_label.config(text=f"錯誤: {wrong_answer_count} ❌")

def clear_options():
    global answer_buttons, button_option_map
    for button in answer_buttons: button.destroy()
    answer_buttons = []; button_option_map = {}

# MODIFIED: Added wraplength and adjusted height/justify
def display_question(q_data):
    global answer_buttons, buttons_enabled, button_option_map
    clear_options()

    wrapped_q = textwrap.fill(q_data['question'], width=80)
    question_label.config(text=wrapped_q)
    feedback_label.config(text="")

    options = q_data['options']
    is_true_false = (len(options) == 2 and set(options) == {'是', '非'})
    if is_true_false:
        options_to_display = ['是', '非']
    else:
        options_to_display = options[:]; random.shuffle(options_to_display)

    center_width = 45
    # --- Wrapping modification ---
    # Estimate pixel width for wraplength. This value might need tuning.
    # Based on width=50 and font size 12, 500 might be a good starting point.
    wrap_pixel_width = 500

    for i, option in enumerate(options_to_display):
        # Keep the number + centered text format
        button_text = f"{i + 1}.  {option:^{center_width}}"

        button = tk.Button(options_frame,
                           text=button_text,
                           font=font_options,
                           width=50, # Keep width for calculation consistency
                           height=2, # <<< Increase height to allow for 2 lines
                           anchor=tk.W,
                           justify=tk.LEFT, # <<< Justify wrapped lines left
                           wraplength=wrap_pixel_width, # <<< Add wraplength
                           bg=DEFAULT_BTN_BG,
                           fg=DEFAULT_BTN_FG,
                           activebackground=DEFAULT_BTN_ACTIVE_BG,
                           state = tk.NORMAL
                           )
        button.config(command=lambda opt=option, btn=button: check_answer(opt, btn))
        button.pack(pady=3) # Slightly reduce vertical padding if needed
        answer_buttons.append(button)
        button_option_map[button] = option

    buttons_enabled = True
    key_hint_label.pack(pady=2)
    update_status_display()

def set_buttons_state(enabled):
    global buttons_enabled; buttons_enabled = enabled
    state = tk.NORMAL if enabled else tk.DISABLED; bg_color = DEFAULT_BTN_BG if enabled else "#DCDCDC"
    fg_color = DEFAULT_BTN_FG
    # Don't reset colors here, check_answer handles feedback colors
    for button in answer_buttons: button.config(state=state) # Only change state

# handle_key_press remains the same
def handle_key_press(event):
    if not game_in_progress or not buttons_enabled: return
    key = event.keysym
    if key in ['1', '2', '3', '4', '5']:
        try:
            index = int(key) - 1
            if 0 <= index < len(answer_buttons):
                clicked_button = answer_buttons[index]
                option_text = button_option_map.get(clicked_button)
                if option_text: check_answer(option_text, clicked_button)
                else: print(f"Warning: Could not find option text for button at index {index}")
        except ValueError: pass
        except IndexError: pass
        except Exception as e: print(f"Error processing key press: {e}")

# check_answer remains the same (handles feedback color)
def check_answer(selected_option, clicked_button):
    global player_score, wrong_answer_count, questions_answered, game_in_progress, buttons_enabled
    if not buttons_enabled: return
    set_buttons_state(False); correct_answer = current_question_data['correct_answer']
    is_correct = (selected_option == correct_answer)
    if is_correct:
        player_score += 1; clicked_button.config(bg=CORRECT_COLOR, fg="white", relief=tk.SUNKEN)
        feedback_label.config(text="✅ 正確！", fg=CORRECT_COLOR)
    else:
        wrong_answer_count += 1; clicked_button.config(bg=WRONG_COLOR, fg="white", relief=tk.SUNKEN)
        feedback_label.config(text=f"❌ 錯誤！答案是: {correct_answer}", fg=WRONG_COLOR)
        for btn, opt_text in button_option_map.items():
            if opt_text == correct_answer: btn.config(bg=CORRECT_HIGHLIGHT_COLOR, relief=tk.GROOVE); break
        if current_question_data not in wrong_answers_list: wrong_answers_list.append(current_question_data.copy())
    questions_answered += 1; update_status_display()
    if questions_answered >= target_questions: window.after(1800, game_over, f"已完成 {target_questions} 題！")
    else: window.after(1800, load_next_question)

# load_next_question remains the same
def load_next_question():
    global current_question_data, buttons_enabled, current_question_index_in_round
    if current_question_index_in_round < len(round_question_indices):
        actual_index = round_question_indices[current_question_index_in_round]
        if 0 <= actual_index < len(FLAT_QUESTION_BANK):
            current_question_data = FLAT_QUESTION_BANK[actual_index]
            current_question_index_in_round += 1
            display_question(current_question_data)
        else:
             print(f"Error: Invalid question index {actual_index} loaded from round list.")
             if game_in_progress: game_over("讀取題目索引時出錯！")
    else:
        print("Warning: Tried to load question beyond target count.")
        if game_in_progress: game_over("已完成所有選定題目！")

# game_over remains the same
def game_over(message):
    global game_in_progress, buttons_enabled
    game_in_progress = False; buttons_enabled = False; clear_options()
    question_label.config(text="挑戰結束！"); question_progress_label.config(text=f"進度: {questions_answered}/{target_questions}")
    feedback_label.config(text=f"{message}\n最終得分: {player_score} | 錯誤題數: {wrong_answer_count}", fg=TEXT_COLOR)
    key_hint_label.pack_forget(); restart_button.pack(side=tk.LEFT, padx=20, pady=10)
    if wrong_answers_list: review_button.pack(side=tk.RIGHT, padx=20, pady=10)
    else: review_button.pack_forget()

# show_review_window remains the same
def show_review_window():
    if not wrong_answers_list: tkinter.messagebox.showinfo("複習", "你沒有答錯任何題目，真厲害！"); return
    review_window = tk.Toplevel(window); review_window.title("錯題複習"); review_window.geometry("550x450"); review_window.configure(bg=BG_COLOR)
    tk.Label(review_window, text="--- 錯題與答案 ---", font=font_title, bg=BG_COLOR, fg=TEXT_COLOR).pack(pady=10)
    review_frame = tk.Frame(review_window); review_frame.pack(pady=5, padx=10, fill=tk.BOTH, expand=True)
    scrollbar = tk.Scrollbar(review_frame); scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
    review_text = tk.Text(review_frame, wrap=tk.WORD, yscrollcommand=scrollbar.set, font=font_review, bg="#FFFFFF", bd=1, relief=tk.SUNKEN)
    review_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True); scrollbar.config(command=review_text.yview)
    review_content = "".join([f"Q{i+1}: {item['question']}\n   => 正確答案: {item['correct_answer']}\n\n" for i, item in enumerate(wrong_answers_list)])
    review_text.insert(tk.END, review_content); review_text.config(state=tk.DISABLED)
    tk.Button(review_window, text="關閉", font=font_button, command=review_window.destroy).pack(pady=10)
    review_window.transient(window); review_window.grab_set(); window.wait_window(review_window)

# setup_game remains the same
def setup_game():
    global target_questions, player_score, wrong_answer_count, questions_answered
    global round_question_indices, current_question_index_in_round
    global wrong_answers_list, game_in_progress, buttons_enabled
    if FLAT_QUESTION_BANK is None or not FLAT_QUESTION_BANK: tkinter.messagebox.showerror("錯誤", "題庫未成功載入，無法開始遊戲。"); return
    try:
        num_str = num_questions_entry.get(); num = int(num_str)
        if num <= 0: tkinter.messagebox.showwarning("輸入錯誤", "請輸入一個正數。"); return
        actual_target = min(num, TOTAL_QUESTIONS_AVAILABLE)
        if num > TOTAL_QUESTIONS_AVAILABLE: tkinter.messagebox.showinfo("提示", f"題庫中只有 {TOTAL_QUESTIONS_AVAILABLE} 題，將挑戰所有題目。")
        target_questions = actual_target
    except ValueError: tkinter.messagebox.showwarning("輸入錯誤", "請輸入有效的數字。"); return
    all_indices = list(range(TOTAL_QUESTIONS_AVAILABLE)); sample_size = min(target_questions, len(all_indices))
    if sample_size <= 0: tkinter.messagebox.showerror("錯誤", "題庫中沒有可用的題目。"); return
    round_question_indices = random.sample(all_indices, sample_size); current_question_index_in_round = 0
    player_score = 0; wrong_answer_count = 0; questions_answered = 0
    wrong_answers_list = []; game_in_progress = True; buttons_enabled = False
    start_frame.pack_forget(); restart_button.pack_forget(); review_button.pack_forget()
    game_frame.pack(fill=tk.BOTH, expand=True); feedback_label.config(text="")
    load_next_question()

# show_start_screen remains the same
def show_start_screen():
    game_frame.pack_forget(); num_questions_entry.delete(0, tk.END)
    num_questions_entry.insert(0, "10"); start_frame.pack(pady=50, fill=tk.BOTH, expand=True)
    num_questions_entry.focus_set()

# --- Bind Keyboard Events (unchanged) ---
window.bind("<KeyPress-1>", handle_key_press)
window.bind("<KeyPress-2>", handle_key_press)
window.bind("<KeyPress-3>", handle_key_press)
window.bind("<KeyPress-4>", handle_key_press)
window.bind("<KeyPress-5>", handle_key_press)
num_questions_entry.bind("<Return>", handle_start_enter)

# --- Initial GUI State ---
show_start_screen()

# --- Start Main Loop ---
window.mainloop()