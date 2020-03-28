data = [1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,5,19,23,2,6,23,27,1,27,5,31,2,9,31,35,1,5,35,39,2,6,39,43,2,6,43,47,1,5,47,51,2,9,51,55,1,5,55,59,1,10,59,63,1,63,6,67,1,9,67,71,1,71,6,75,1,75,13,79,2,79,13,83,2,9,83,87,1,87,5,91,1,9,91,95,2,10,95,99,1,5,99,103,1,103,9,107,1,13,107,111,2,111,10,115,1,115,5,119,2,13,119,123,1,9,123,127,1,5,127,131,2,131,6,135,1,135,5,139,1,139,6,143,1,143,6,147,1,2,147,151,1,151,5,0,99,2,14,0,0]

def part_one():
    data[1] = 12
    data[2] = 2
    ip = 0
    while True:
        op = data[ip]
        if op == 99:
            break
        a = data[ data[ip+1]]
        b = data[ data[ip+2]]
        dest = data[ip+3]
        if op == 1:
            data[dest] =  a + b
        elif op == 2:
            data[dest] = a * b
        else:
            break
        ip = ip + 4
    print(data[0])
    
def run_program(program):
	ip = 0
	while True:
        	op = program[ip]
        	if op == 99:
            		break
	        a = program[ program[ip+1] ]
        	b = program[ program[ip+2] ]
        	dest = program[ip+3]
        	if op == 1:
            		program[dest] =  a + b
        	else:
            		program[dest] = a * b
        	ip = ip + 4
	return program[0]

def part2(data):
	results = []
	for noun in range(100):
	    for verb in range(100):
            	program = data[:]
            	program[1] = noun
            	program[2] = verb
            	r = run_program(program)
            	results.append( (100*noun+verb, r))
	ans = [ x for x in results if x[1]==19690720]
	return ans

print(part2(data))
