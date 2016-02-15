class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;

        if(divisor == numeric_limits<int>::min())
        {
            if(dividend == divisor)
                return 1;
            else 
                return 0;
        }
        else
        {
            int result = 0;
            if(dividend == numeric_limits<int>::min())
            {
                if(divisor == 1)
                    return numeric_limits<int>::min();
                else if(divisor == -1)
                    return numeric_limits<int>::max();
                else
                {
                    if(divisor > 0)
                        dividend += divisor;
                    else
                        dividend -= divisor;
                    result++;
                }
            }
            bool pos = true;
            if(dividend > 0 && divisor < 0)
            {
                divisor = 0 - divisor;
                pos = false;
            }
            else if(dividend < 0 && divisor > 0)
            {
                dividend = 0 - dividend;
                pos = false;
            }
            else if(dividend < 0 && divisor < 0)
            {
                dividend = 0 - dividend;
                divisor = 0 - divisor;
            }
            if(dividend < divisor)
            {
                if(pos)
                    return result;
                else
                    return 0-result;
            }
            else
            {
                while(dividend > divisor)
                {
                    int count = 0;
                    while(dividend>>1 >= divisor)
                    {
                        divisor = divisor<<1;
                        count++;
                    }
                    dividend -= divisor;
                    result += 1<<count;
                    divisor = divisor>>count;
                }
                if(dividend == divisor)
                    result++;
                if(pos)
                    return result;
                else
                    return 0-result;
            }
        }
        
        
    }
};
