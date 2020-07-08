/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package usaco.practice.previousContests.years1819;

import java.util.*;
import java.io.*;

public class BucketList {
    public static void main(String[] args) throws IOException{
        BufferedReader read = new BufferedReader(new FileReader("blist.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("blist.out")));
        
        int n = Integer.parseInt(read.readLine());
        
        Point[] things = new Point[n];
        
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            
            Point a = new Point(x, y, z);
            things[i] = a;
        }
        
        Arrays.sort(things);
        System.out.println(Arrays.toString(things));
        
        for (int i = things[0].getX(); i < things[n-1].getY(); i++) {
            
        }
    }
}

class Point implements Comparable<Point>{
    private int x;
    private int y;
    private int z;
    
    public Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public int getX() {
        return x;
    }
    
    @Override
    public int compareTo(Point other) {
        return this.x - other.x; // or whatever property you want to sort
    }
    public int getY() {
        return y;
    }
    
    public int getZ() {
        return z;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }
    
    public void setZ(int z) {
        this.z = z;
    }
    
    @Override
    public String toString() {
        return "(" + x + ", " + y + ", " + z + ")";
    }
    
}
