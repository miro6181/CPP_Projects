def grade_calc():
    problem_sets = sum([19.75, 20, 19.4, 17.7, 14, 23])
    explain_it_back = sum([25, 13, 26, 17, 10, 28, 30])
    multiple_choice = 30
    midterm = 29.25
    final = 0
    GC = 0

    return problem_sets + explain_it_back + multiple_choice + midterm + final + GC + 100

print(grade_calc())
