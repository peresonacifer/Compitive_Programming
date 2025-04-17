#include <iostream>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i<N; i++)
    {
        int D, S;
        cin >> D >> S;
        if (S == 1)
        {
            int count = D-1;
            for (int j = 0; j<D; j++)
            {
                for (int k = 0; k<D; k++)
                {
                    if (k != 0) cout << " ";
                    if (k == count)
                    {
                        count--;
                        cout << "*";
                    }
                    else cout << "x";
                }
                cout << "\n";
            }
        }
        else if (S == 2)
        {
            int count = 0;
            for (int j = 0; j<D; j++)
            {
                bool ok = true;
                for (int k = 0; k<D; k++)
                {
                    if (k != 0) cout << " ";
                    if (k == count && ok)
                    {
                        ok = false;
                        count++;
                        cout << "*";
                    }
                    else cout << "x";
                }
                cout << "\n";
            }
        }
        else if (S == 3)
        {
            for (int j = 0; j<D; j++)
            {
                for (int k = 0; k<D; k++)
                {
                    if (k != 0) cout << " ";
                    if (k == D-1) cout << "*";
                    else cout << "x";
                }
                cout << "\n";
            }
        }
        else
        {
            for (int j = 0; j<D; j++)
            {
                for (int k = 0; k<D; k++)
                {
                    if (k != 0) cout << " ";
                    if (k == 0) cout << "*";
                    else cout << "x";
                }
                cout << "\n";
            }
        }
    }
}