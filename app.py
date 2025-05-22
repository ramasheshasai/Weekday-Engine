from flask import Flask, render_template, request

app = Flask(__name__)

def check_leap(year):
    if year % 100 == 0:
        return year % 400 == 0
    else:
        return year % 4 == 0

def check_date(year, month, date, leap):
    if month > 12 or month < 1:
        return False
    if leap:
        if month == 2:
            return 1 <= date <= 29
        elif month <= 7:
            if month % 2 == 1:
                return 1 <= date <= 31
            else:
                return 1 <= date <= 30
        else:
            if month % 2 == 1:
                return 1 <= date <= 30
            else:
                return 1 <= date <= 31
    else:
        if month == 2:
            return 1 <= date <= 28
        elif month <= 7:
            if month % 2 == 1:
                return 1 <= date <= 31
            else:
                return 1 <= date <= 30
        else:
            if month % 2 == 1:
                return 1 <= date <= 30
            else:
                return 1 <= date <= 31

def month_code(month):
    codes = {
        1:0, 2:3, 3:3, 4:6, 5:1, 6:4,
        7:6, 8:2, 9:5, 10:0, 11:3, 12:5
    }
    return codes.get(month, -1)

def century_code(year):
    if 2000 <= year < 2100:
        return 6
    elif 1600 <= year < 1700:
        return 6
    elif 1700 <= year < 1800:
        return 4
    elif 1800 <= year < 1900:
        return 2
    elif 1900 <= year < 2000:
        return 0
    else:
        return -1

def year_remainder(year):
    return year % 100

def quotient(year):
    return (year % 100) // 4

def calculate_day(date, month, year):
    a = date
    b = month_code(month)
    dVal = year_remainder(year)
    e = quotient(year)
    f = century_code(year)
    if b == -1 or f == -1:
        return -1
    dayOfWeek = (a + b + dVal + e + f) % 7
    return dayOfWeek

def get_day_name(day_code):
    days = {
        0:"Sunday",
        1:"Monday",
        2:"Tuesday",
        3:"Wednesday",
        4:"Thursday",
        5:"Friday",
        6:"Saturday"
    }
    return days.get(day_code, "Invalid date")

@app.route('/', methods=['GET', 'POST'])
def index():
    result = None
    details = None
    show_details = False
    if request.method == 'POST':
        try:
            date = int(request.form['date'])
            month = int(request.form['month'])
            year = int(request.form['year'])
            show_details = 'details' in request.form
            
            leap = check_leap(year)
            valid = check_date(year, month, date, leap)
            if not valid:
                result = "Invalid date!"
            else:
                day_code = calculate_day(date, month, year)
                if day_code == -1:
                    result = "Date or year out of supported range."
                else:
                    day_name = get_day_name(day_code)
                    leap_str = "You are born in a leap year" if leap else "Not born in a leap year"
                    result = f"The day of the week is: {day_name}. {leap_str}."
                    
                    if show_details:
                        # Prepare calculation details like printDetails from your code
                        details = {
                            "Date": date,
                            "Month Code": month_code(month),
                            "Year": year_remainder(year),
                            "Century Code": century_code(year),
                            "Quotient": quotient(year),
                            "Sum": date + month_code(month) + year_remainder(year) + century_code(year) + quotient(year),
                            "Remainder (Sum % 7)": (date + month_code(month) + year_remainder(year) + century_code(year) + quotient(year)) % 7
                        }
        except ValueError:
            result = "Please enter valid integer values for date, month, and year."

    return render_template('index.html', result=result, details=details, show_details=show_details)

if __name__ == "__main__":
    app.run(debug=True)
