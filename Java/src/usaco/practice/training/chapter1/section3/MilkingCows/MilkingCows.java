/*
 USER: shourya7
 LANG: JAVA
 TASK: milk2
 */
import java.util.*;
import java.io.*;

class milk2 {
    static int continuous;
    static int idle;
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));

        int N = Integer.parseInt(read.readLine());

        boolean[] nums = new boolean[N];
        //Faster sorting
        int[] starts = new int[N];
        int[] ends = new int[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            starts[i] = Integer.parseInt(st.nextToken());
            ends[i] = Integer.parseInt(st.nextToken());
        }

        int maxMilking = -1;
        ArrayList<Range> ranges = new ArrayList<>();
        //Finds maximum value
        for (int i = 0; i < N; i++) {
            if (nums[i]) continue;
            int initStart = starts[i];
            int maxEnd = ends[i];
            nums[i] = true;
            for (int k = 0; k < N; k++) {
                if (nums[k]) continue;
                if (starts[k] >= initStart) {
                    if (ends[k] <= maxEnd) {
                        nums[k] = true;
                        continue;
                    }
                    else if (starts[k] <= maxEnd && ends[k] > maxEnd) {
                        maxEnd = ends[k];
                        nums[k] = true;
                        continue;
                    }
                }
                if (starts[k] <= initStart) {
                    if (ends[k] >= maxEnd)  {
                        initStart = starts[k];
                        maxEnd = ends[k];
                        nums[k] = true;
                        k = 0;
                    }
                    else if (ends[k] >= initStart) {
                        initStart = starts[k];
                    }
                }
            }
            ranges.add(new Range(initStart, maxEnd));
        }


        ranges.sort((o1, o2) -> {
            if (o1.start == o2.start) return o1.end - o2.end;
            else return o1.start - o2.start;
        });

        for (int i = ranges.size() - 1; i > 0; i--) {
            if (ranges.get(i).start < ranges.get(i - 1).end) {
                ranges.get(i - 1).end = ranges.get(i).end;
                ranges.remove(i);
            }
        }
        System.out.println(ranges);

        for (Range r : ranges) {
            if (r.length() > maxMilking) maxMilking = r.length();
        }


        out.print(maxMilking + " ");

        int maxGap = 0;
        for (int i = 0; i < ranges.size() - 1; i++) {
            if (ranges.get(i + 1).start - ranges.get(i).end > maxGap)
                maxGap = ranges.get(i + 1).start - ranges.get(i).end;
        }

        out.print(maxGap + "\n");
        out.close();
    }

    static class Range {
        public int start;
        public int end;

        public Range(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int length() {
            return end - start;
        }

        @Override
        public String toString() {
            return "[" + start + ", " + end + "]";
        }
    }
}
