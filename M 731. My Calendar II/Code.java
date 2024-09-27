import java.util.ArrayList;
import java.util.List;

class MyCalendarTwo {
    private List<int[]> bookings, overlaps; // bookings and overlaps

    public MyCalendarTwo() {
        bookings = new ArrayList<>();
        overlaps = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        for (int[] o : overlaps) { // Check for overlaps
            if (start < o[1] && end > o[0]) return false;
        }
        for (int[] b : bookings) { // Store new overlaps
            if (start < b[1] && end > b[0]) {
                overlaps.add(new int[]{Math.max(start, b[0]), Math.min(end, b[1])});
            }
        }
        bookings.add(new int[]{start, end}); // Store the new booking
        return true;
    }

    public static void main(String[] args) {
        MyCalendarTwo myCalendar = new MyCalendarTwo();
        System.out.println(myCalendar.book(10, 20)); // Output: true
        System.out.println(myCalendar.book(15, 25)); // Output: true
        System.out.println(myCalendar.book(20, 30)); // Output: true
        System.out.println(myCalendar.book(5, 15));  // Output: false
    }
}
