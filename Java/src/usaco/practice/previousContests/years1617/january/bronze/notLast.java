/*
ID: shourya7
LANG: JAVA
TASK: NOTLAST
 */

import java.util.*;
import java.io.*;
public class notLast {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("notlast.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));
        
        //The Cows:
        short Bessie = 0;
        short Elsie = 0;
        short Daisy = 0;
        short Gertie = 0;
        short Annabelle = 0;
        short Maggie = 0;
        short Henrietta = 0;
        
        byte reps = Byte.parseByte(read.readLine());
        
        String cowName;   
        Short amount;
        for (byte i = 0; i < reps; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            cowName = st.nextToken();
            amount = Short.parseShort(st.nextToken());
            if (cowName.equals("Bessie")){
                Bessie += amount;
            }
            else if (cowName.equals("Elsie")){
                Elsie += amount;
            }
            else if (cowName.equals("Daisy")){
                Daisy += amount;
            }
            else if (cowName.equals("Gertie")){
                Gertie += amount;
            }
            else if (cowName.equals("Annabelle")){
                Annabelle += amount;
            }
            else if (cowName.equals("Maggie")){
                Maggie += amount;
            }
            else if (cowName.equals("Henrietta")){
                Henrietta += amount;
            }
        }
        short[] values = {Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, Henrietta};
        Arrays.sort(values);
        
        byte reps2 = 1;
        short secondLargest = 0;
        
        for (byte i = 0; i < reps2; i++){
            if (values[i]==values[0]){
                reps2++;
            }
            else if (values[i]>values[0]){
                secondLargest = values[i];
                reps2 = 0;
            }
         }
        
        if (Bessie == secondLargest){
            out.println("Bessie");
        }
        else if (Elsie == secondLargest) {
            out.println("Elsie");
        }
        else if (Daisy == secondLargest) {
            out.println("Daisy");
        }
        else if (Gertie == secondLargest) {
            out.println("Gertie");
        }
        else if (Annabelle == secondLargest) {
            out.println("Annabelle");            
        }
        else if (Maggie == secondLargest) {
            out.println("Maggie");
        }
        else if (Henrietta == secondLargest) {
            out.println("Henrietta");
        }
        out.close();
    }
    
}
