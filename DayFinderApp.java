import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DayFinderApp extends JFrame implements ActionListener {
    JTextField dayField, monthField, yearField;
    JTextArea outputArea;
    JButton findButton, clearButton;
    static int checkCount = 0;

    public DayFinderApp() {
        setTitle("Day Finder");
        setSize(450, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        add(new JLabel("Enter Date:"));
        dayField = new JTextField(10);
        add(dayField);

        add(new JLabel("Enter Month:"));
        monthField = new JTextField(10);
        add(monthField);

        add(new JLabel("Enter Year:"));
        yearField = new JTextField(10);
        add(yearField);

        findButton = new JButton("Find Day");
        findButton.addActionListener(this);
        add(findButton);

        clearButton = new JButton("Clear");
        clearButton.addActionListener(e -> {
            dayField.setText("");
            monthField.setText("");
            yearField.setText("");
            outputArea.setText("");
        });
        add(clearButton);

        outputArea = new JTextArea(20, 40);
        outputArea.setEditable(false);
        add(new JScrollPane(outputArea));
    }

    public void actionPerformed(ActionEvent e) {
        try {
            int date = Integer.parseInt(dayField.getText());
            int month = Integer.parseInt(monthField.getText());
            int year = Integer.parseInt(yearField.getText());

            if (!isValidDate(date, month, year)) {
                outputArea.setText("Invalid Date!");
                return;
            }

            int monthCode = getMonthCode(month);
            int yearPart = year % 100;
            int quotient = yearPart / 4;
            int centuryCode = getCenturyCode(year);

            int sum = date + monthCode + yearPart + quotient + centuryCode;
            int dayOfWeek = sum % 7;

            String[] days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
            String day = days[dayOfWeek];

            checkCount++;

            boolean isLeap = isLeapYear(year);
            String leapMsg = isLeap ? "Yes, it's a leap year." : "No, it's not a leap year.";

            StringBuilder sb = new StringBuilder();
            sb.append("Date Entered: ").append(date).append("/").append(month).append("/").append(year).append("\n");
            sb.append("Day of the week: ").append(day).append("\n");
            sb.append("Leap Year? ").append(leapMsg).append("\n\n");

            sb.append("---- Calculations ----\n");
            sb.append("Date: ").append(date).append("\n");
            sb.append("Month Code: ").append(monthCode).append("\n");
            sb.append("Year Part: ").append(yearPart).append("\n");
            sb.append("Quotient (YearPart/4): ").append(quotient).append("\n");
            sb.append("Century Code: ").append(centuryCode).append("\n");
            sb.append("Sum: ").append(sum).append("\n");
            sb.append("Sum % 7 = ").append(dayOfWeek).append(" → ").append(day).append("\n");
            sb.append("Checked ").append(checkCount).append(" time(s)");

            outputArea.setText(sb.toString());

        } catch (NumberFormatException ex) {
            outputArea.setText("Please enter valid numbers for date, month, and year.");
        }
    }

    private boolean isLeapYear(int year) {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    }

    private boolean isValidDate(int date, int month, int year) {
        if (month < 1 || month > 12) return false;
        int[] daysInMonth = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31};
        return date >= 1 && date <= daysInMonth[month - 1];
    }

    private int getMonthCode(int month) {
        switch (month) {
            case 1: return 0;
            case 2: return 3;
            case 3: return 3;
            case 4: return 6;
            case 5: return 1;
            case 6: return 4;
            case 7: return 6;
            case 8: return 2;
            case 9: return 5;
            case 10: return 0;
            case 11: return 3;
            case 12: return 5;
            default: return -1;
        }
    }

    private int getCenturyCode(int year) {
        int century = year / 100;
        if (century == 16 || century == 20) return 6;
        if (century == 17) return 4;
        if (century == 18) return 2;
        if (century == 19) return 0;
        return -1; // For unsupported centuries
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new DayFinderApp().setVisible(true);
        });
    }
}
