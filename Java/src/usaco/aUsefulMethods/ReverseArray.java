package usaco.aUsefulMethods;

/**
 * A Method to Reverse an array from a start index and an end index
 */
public class ReverseArray {
    public static void reverseArray(int[] array, int begin, int end) {
        for (int i = begin; i < begin + (end - begin) / 2.0 + 0.5; i++) {
            int temp = array[i];
            array[i] = array[end + begin - i];
            array[end + begin - i] = temp;
        }
    }
}
