import java.io.*;
import java.util.*;
public class NotLastSolution {
	static String[] cows;
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("notlast.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));
		
		// initialize an array with all the cow names
		cows = new String[]{
				"Bessie",
				"Elsie",
				"Daisy",
				"Gertie",
				"Annabelle",
				"Maggie",
				"Henrietta"};
		
		// allocate an array to count how much milk each cow produces
		int[] amount = new int[cows.length];
		
		// read in the number of log entries
		int n = Integer.parseInt(br.readLine());
		
		// loop over the entries
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			// read the name of the cow and the amount of milk
			String name = st.nextToken();
			int milk = Integer.parseInt(st.nextToken());
			
			// update the amount of milk for the given cow
			amount[findCowIndex(name)] += milk;
		}
		
		// compute the minimum amount of milk produced
		int minimumAmount = 1000000;
		for(int i = 0; i < amount.length; i++) {
			if(amount[i] < minimumAmount) {
				minimumAmount = amount[i];
			}
		}
		
		// compute the second smallest amount of milk produced 
		int secondSmallestAmount = 1000000;
		for(int i = 0; i < amount.length; i++) {
			// the second smallest amount of milk must be larger than the smallest amount of milk
			if(amount[i] > minimumAmount && amount[i] < secondSmallestAmount) {
				secondSmallestAmount = amount[i];
                        }
		}
		
		// determine the cow that milked the second-smallest amount of milk 
		final int NOT_FOUND = -1;
		final int MORE_THAN_ONE = -2;
		int indexOfSecondSmallest = NOT_FOUND;
		for(int i = 0; i < amount.length; i++) {
			if(amount[i] == secondSmallestAmount) {
				if(indexOfSecondSmallest == NOT_FOUND) {
					// we haven't found any cow yet, so that cow has milked the correct amount
					indexOfSecondSmallest = i;
				}
				else {
					// we have found at least two cows, so there is a tie
					indexOfSecondSmallest = MORE_THAN_ONE;
				}
			}
		}
                		
		// print the answer
		if(indexOfSecondSmallest >= 0) {
			pw.println(cows[indexOfSecondSmallest]);
		}
		else {
			pw.println("Tie");
		}
		
		// close the file
		pw.close();
	}
	
	public static int findCowIndex(String s) {
		// This function takes in the name of a cow and returns the index where
		// that name can be found in the array of names.
		for(int i = 0; i < cows.length; i++) {
			if(cows[i].equals(s)) {
				return i;
			}
		}
		return -1;
	}
	
}