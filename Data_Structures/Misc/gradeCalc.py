def gradeCalc(hws, recitaion, midterm_1, midterm_2, project):

    hw_sum = 0
    for hw in hws:
        hw_sum += hw
    hw_avg = hw_sum/(len(hws) * 100)

    quiz_avg = 0.7505

    grade = (0.45 * hw_avg) + (0.1 * quiz_avg) + (0.1 * (midterm_1/100)) + (0.1 * (midterm_2/100)) + (0.1 * (project/100) + (0.15 * recitaion/100))

    letter = ""

    if grade >= 0.93:
        letter = "A"
    elif grade >= 0.90 and grade < 0.93:
        letter = "A-"
    elif grade >= 0.87 and grade < 0.90:
        letter = "B+"
    elif grade >= 0.83 and grade < 0.87:
        letter = "B"
    elif grade >= 0.80 and grade < 0.83:
        letter = "B-"
    elif grade >= 0.77 and grade < 0.80:
        letter = "C+"
    elif grade >= 0.73 and grade < 0.77:
        letter = "C"
    elif grade >= 0.70 and grade < 0.73:
        letter = "C-"
    elif grade >= 0.67 and grade < 0.70:
        letter = "D+"
    elif grade >= 0.63 and grade <= 0.66:
        letter = "D"
    elif grade >= 0.60 and grade <= 0.62:
        letter = "D-"
    else:
        letter = "F"

    return "Your Grade is: " + letter + " (" + str((float(grade) * 100)) + " %" + ")"

print(gradeCalc([85.00, 70.00, 100.00, 40.00, 48.00, 49.67, 75.00, 100.00, 45.00], 90, 95, 65, 100))
