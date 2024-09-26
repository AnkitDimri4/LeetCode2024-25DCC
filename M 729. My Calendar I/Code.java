import java.util.ArrayList;
import java.util.List;

class MyCalendar {
    private List<int[]> bookings;
    
    public MyCalendar() {
        bookings = new ArrayList<>();
    }
    
    public boolean book(int start, int end) {
        for (int[] b : bookings) {
            if (start < b[1] && end > b[0]) return false;
        }
        bookings.add(new int[] {start, end});
        return true;
    }
    
    public static void main(String[] args) {
        MyCalendar myCalendar = new MyCalendar();
        System.out.println(myCalendar.book(10, 20)); // true
        System.out.println(myCalendar.book(15, 25)); // false
        System.out.println(myCalendar.book(20, 30)); // true
    }
}
