class Solution:
    def calPoints(self,operations):
        if not operations:
            return 0
           
        result=[]
       
        for i in range(len(operations)):
            if operations[i] == 'C':
                result.pop()
            elif operations[i] == 'D':
                last = result[-1]
                result.append(2*last)
            elif operations[i] == "+":
                result.append(result[-1]+result[-2])
            else:
                result.append(int(operations[i]))  
               
        sumation=0
        for i in range(len(result)):
            sumation += result[i]
       
        return sumation
               
               
               
               


# 🔽 Main
if __name__ == "__main__":
    ops = ["5","2","C","D","+"]
   
    sol = Solution()
    print("Total Score:", sol.calPoints(ops))

