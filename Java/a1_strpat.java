/*
Write a Java program to print numbers in the following format using do-while
loop
Input: 12345
Output: 12345
		1234
		123
		12
		1
*/

import java.util.Scanner;

class StringPattern {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter string: ");
		String str = sc.nextLine();
		int lpos = str.length();

		do {
			for (int i = 0; i < lpos; i++)
				System.out.print(str.charAt(i));

			System.out.println();
			lpos--;
		} while (lpos >= 0);
	}
}