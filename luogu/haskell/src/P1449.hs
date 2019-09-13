module P1449 where

readFullNumber' :: String -> String -> (Int, String)
readFullNumber' ('.':xs) s = (read s, xs)
readFullNumber' (x:xs) s = readFullNumber' xs (s ++ [x])

readFullNumber :: String -> (Int, String)
readFullNumber = flip readFullNumber'  ""

-- eval :: Stack -> Formula -> Result
eval :: [Int] -> String -> Int
eval (a:s) [] = a
eval (a:b:s) ('+':xs) = eval (b + a : s) xs
eval (a:b:s) ('-':xs) = eval (b - a : s) xs
eval (a:b:s) ('*':xs) = eval (b * a : s) xs
eval (a:b:s) ('/':xs) = eval (b `div` a : s) xs
eval s xs = eval (number : s) str
  where
    fullNumber = readFullNumber xs
    number = fst fullNumber
    str = snd fullNumber
  
  
main :: IO ()
main = do
  s <- getLine

  print $ eval [] (take (length s - 1) s)
