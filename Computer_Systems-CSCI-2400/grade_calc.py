def grade_calc(exams, homeworks):
    grade_sum = 0
    for exam in exams:
        grade_sum += (exam * 0.1)
    for homework in homeworks:
        grade_sum += (homework * 0.1)

    return grade_sum

print(grade_calc([60,61,60,60],[82,95,89,88,88,88]))
