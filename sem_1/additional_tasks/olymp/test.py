def validate_battlefield(field):   

    def coords_check(i, j):
        return 0 <= i <= 9 and 0 <= j <= 9

    avaliable_amount = {
        1: 4,
        2: 3,
        3: 2,
        4: 1
    }

    step_sequence = [
        [0, 1],
        [1, 0]
    ]

    for i in range(10):
        for j in range(10):
            if field[i][j] == 1:
                current_len = 1
                step_index = 0 
                
                current_i = i
                current_j = j

                if field[current_i + step_sequence[step_index][0]][current_j + step_sequence[step_index][1]] == 0:
                    step_index = 1


                while current_len < 4 and  field[current_i + step_sequence[step_index][0]][current_j + step_sequence[step_index][1]] == 1:
                    field[current_i][current_j] = 0
                    
                    if not coords_check(current_i + step_sequence[step_index][0], current_j + step_sequence[step_index][1]):
                        break

                    current_i += step_sequence[step_index][0]
                    current_j += step_sequence[step_index][1]

                    current_len += 1

                field[current_i][current_j] = 0
                    
                avaliable_amount[current_len] -= 1

                if avaliable_amount[current_len] < 0:
                    return False

                #check around
                
                #up
                for c_j in range(j - 1, current_j + 1 + 1):
                    if coords_check(i - 1, c_j):
                        if field[i - 1][c_j] == 1:
                            return False

                #left
                for c_i in range(i, current_i + 1):
                    if  coords_check(c_i, j - 1):
                        if field[c_i][j - 1] == 1:
                            return False
                
                #down
                for c_j in range(j - 1, current_j + 1 + 1):
                    if  coords_check(current_i + 1, c_j):
                        if field[current_i + 1][c_j] == 1:
                            return False

                #right
                for c_i in range(i, current_i + 1):
                    if coords_check(c_i, current_j + 1):
                        if field[c_i][current_j + 1] == 1:
                            return False

    for i in range(1, 5):
        if avaliable_amount[i] != 0:
            return False
    
    return True

test = [[1, 0, 0, 0, 0, 1, 1, 0, 0, 0],
        [1, 0, 1, 0, 0, 0, 0, 0, 1, 0],
        [1, 0, 1, 0, 1, 1, 1, 0, 1, 0],
        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
        [0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

print(validate_battlefield(test))
