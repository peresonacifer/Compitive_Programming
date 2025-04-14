package ACJAVA;

import java.util.Scanner;

public class MainClass {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n[] = new int[]{8, 3, 5, 4, 9, 2};
        System.out.print("排  序  前:    ");
        for(int i = 0; i < n.length; i++) {
            System.out.print(n[i] + "     ");
        }
        System.out.println("");
        int i;
        for(i = n.length - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                if(n[j] > n[j + 1]) {
                    int temp = n[j];
                    n[j] = n[j + 1];
                    n[j + 1] = temp;
                }
            }
            System.out.print("第 "+ (n.length - 2 - i) + " 次循環:   ");
            for(int k = 0; k < n.length; k++) {
                System.out.print(n[k] + "     ");
            }
            System.out.println("");
        }
        System.out.print("排  序  後:    ");
        for(i = 0; i < n.length; i++) {
            System.out.print(n[i] + "     ");
        }
        System.out.println("");
        // Scanner sc = new Scanner(System.in);
        // for(int i = n.length - 2; i >= 0; i--) {
            //     for(int j = 0; j <= i; j++) {
                //         if(n[j] > n[j + 1]) {
                    //             int temp = n[j];
                    //             n[j] = n[j + 1];
                    //             n[j + 1] = temp;
        //         }
        //     }
        // }
        // for(int i = 0; i < n.length; i++) {
        //     System.out.print(n[i] + " ");
        // }
        // System.out.println("");














        // int tar = sc.nextInt();
        
        // int l = 0,  r = n.length;
        // while(l < r) { // lower_bound();
        //     int mid = (l + r) / 2;
        //     if(n[mid] < tar) {
        //         l = mid + 1;
        //     }
        //     else {
        //         r = mid;
        //     }
        // }


        // if(l >= n.length) {
        //     System.out.println("Not Found");
        // }
        // else System.out.println(n[l]);
        // l = 0; r = n.length;
        // while(l < r) {
        //     int mid = (l + r + 1) / 2;
        //     if(n[mid] <= tar) {
        //         l = mid;
        //     }
        //     else {
        //         r = mid - 1;
        //     }
        // }
        // if(l >= n.length) {
        //     System.out.println("Not Found");
        // }
        // else System.out.println(n[l]);

        sc.close();
    }
}