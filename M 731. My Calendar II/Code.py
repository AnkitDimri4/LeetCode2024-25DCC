class MyCalendarTwo:
    def __init__(self):
        self.bookings = []  # List to store all bookings
        self.overlaps = []  # List to store overlaps

    def book(self, start: int, end: int) -> bool:
        for o in self.overlaps:  # Check for overlaps
            if start < o[1] and end > o[0]:
                return False
        for b in self.bookings:  # Store new overlaps
            if start < b[1] and end > b[0]:
                self.overlaps.append([max(start, b[0]), min(end, b[1])])
        self.bookings.append([start, end])  # Store the new booking
        return True

# Testing the MyCalendarTwo class
my_calendar = MyCalendarTwo()
print(my_calendar.book(10, 20))  # Output: True
print(my_calendar.book(15, 25))  # Output: True
print(my_calendar.book(20, 30))  # Output: True
print(my_calendar.book(5, 15))   # Output: False
