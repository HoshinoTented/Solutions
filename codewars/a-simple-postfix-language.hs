module Postfix where

data Operator = Begin Operator | Push Int Operator | Add Operator | End

eval :: [Int] -> Operator -> Int
eval xs (Begin o) = eval xs o
eval xs (Push a o) = eval (a:xs) o
eval (x:y:s) (Add o) = eval ((x + y) : s) o
eval (x:s) End = x

begin :: Operator -> Int
begin a = eval [] (Begin a)

push :: Int -> Operator -> Operator
push = Push

add :: Operator -> Operator
add = Add

end :: Operator
end = End
