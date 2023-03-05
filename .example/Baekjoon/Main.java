package Baekjoon;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
  private static BufferedReader br;

  public static void main(String[] args) throws IOException{
    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    for(String line = br.readLine();line != null;line = br.readLine()) 
      System.out.println(line);

    br.close();
    return;
  }
}