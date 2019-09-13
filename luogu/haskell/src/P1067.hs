module P1067 (main) where

toString :: Int -> String
toString 0 = ""
toString 1 = "+"
toString (-1) = "-"
toString x = (if x > 0 then '+' : show x else show x)

-- print' :: Max Count (Final) -> Currnet Number -> Number List -> String
print' :: Int -> Int -> [Int] -> String
print' _ 0 (x:xs) = toString x ++ (if x == 1 || x == (-1) then "1" else "")
print' n c (0:xs) = (print' n (c - 1) xs)
print' _ 1 (x:xs) = toString x ++ "x" ++ (print' undefined 0 xs)
print' n c (x:xs) = toString x ++ "x^" ++ (show c) ++ (print' n (c - 1) xs)

main :: IO ()
main = do
  n <- read <$> getLine :: IO Int
  ns <- (map read . words) <$> getLine :: IO [Int]
  str <- pure $ print' n n ns

  putStrLn $ if head str == '+' then
      drop 1 str
    else
      str
    
