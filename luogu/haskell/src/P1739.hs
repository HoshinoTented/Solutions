module P1739 where

-- TODO RE #3

checkPairs' :: [Char] -> String -> Bool
checkPairs' xs [] = length xs == 0
checkPairs' xs ('@':_) = checkPairs' xs []
checkPairs' s ('(':xs) = checkPairs' ('(' : s) xs
checkPairs' ('(':s) (')':xs) = checkPairs' s xs
checkPairs' _ (')':_) = False
checkPairs' s (_:xs) = checkPairs' s xs

checkPairs :: String -> Bool
checkPairs = checkPairs' []

main :: IO ()
main = do
  expr <- getLine

  putStrLn $ if checkPairs expr then "YES" else "NO"
