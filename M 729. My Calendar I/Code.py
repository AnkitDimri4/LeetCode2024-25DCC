class MyCalendar:
    def __init__(self):
        self.bookings = []

    def book(self, start: int, end: int) -> bool:
        for b_start, b_end in self.bookings:
            if start < b_end and end > b_start:
                return False
        self.bookings.append((start, end))
        return True

if __name__ == "__main__":
    my_calendar = MyCalendar()
    print(my_calendar.book(10, 20))  # True
    print(my_calendar.book(15, 25))  # False
    print(my_calendar.book(20, 30))  # True
