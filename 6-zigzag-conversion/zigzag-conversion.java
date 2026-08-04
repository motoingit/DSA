class Solution {
    public String convert(String s, int numRows) {

        if (numRows == 1 || numRows >= s.length())
            return s;

        int len = 2 * numRows - 2;

        StringBuilder[] sbs = new StringBuilder[numRows];

        for (int i = 0; i < numRows; i++)
            sbs[i] = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {

            int index = i % len;

            if (index < numRows) {
                sbs[index].append(s.charAt(i));
            } else {
                sbs[len - index].append(s.charAt(i));
            }
        }

        for (int i = 1; i < numRows; i++)
            sbs[0].append(sbs[i]);

        return sbs[0].toString();
    }
}