/* Write a Java program to find the duplicate words in a string */

import java.util.Scanner;

class DuplicateWords{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string: ");
        String str = sc.nextLine().toLowerCase();

        String[] words = str.split(" ");
        
        System.out.println("Duplicate words: ");
        for(int i = 0; i < words.length; i++){
            int count = 0;
            
            for(int j = i+1; j < words.length; j++)
                if(words[i].equals(words[j])){
                    count++;
                    words[j] = "0";
                }

            if(count > 0 && words[i] != "0")
                System.out.println(words[i]);

        }
            
    }
}
