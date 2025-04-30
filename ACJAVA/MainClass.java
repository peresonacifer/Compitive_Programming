package ACJAVA;

import java.util.Scanner;
import java.util.*;
import java.util.Arrays;

public class MainClass {

    public static void main(String[] args) {
        int[] array = new int[] {10, 20, 30, 40, 50};
        modifyAarry(array);
        System.out.println("被修改後的陣列內容:");
        for(int i = 0; i < array.length; i++) {
            System.out.print(array[i] + ((i < array.length - 1) ? " " : "\n"));
        }
        System.out.printf("平均值為:%.1f\n", average(array));
    }
    
    static void modifyAarry(int[] array) {
        for (int i = 0; i < array.length; i++) {
            array[i] /= 10;
        }
    }

    static double average(int[] array) {
        double sum = 0;
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        return sum / array.length;
    }
}