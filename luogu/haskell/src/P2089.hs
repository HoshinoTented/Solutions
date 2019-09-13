module P2089 where
-- TODO WA

-- dfs :: Programs -> Current Program -> Current -> Need -> Programs (Return)
dfs :: [[Int]] -> [Int] -> Int -> Int -> [[Int]]
dfs ps cp 10 0 = cp : ps
dfs ps _ 10 need = ps
dfs ps _ cur 0 = ps
dfs ps cp cur need = foldr (\x ps -> ps ++ dfs [] (x : cp) (cur + 1) (need - x)) ps [1..3]

printList :: [[Int]] -> IO ()
printList [] = putStr ""
printList (x:xs) = do
  putStrLn $ foldr (\x s -> show x ++ " " ++ s) [] x
  printList xs

main :: IO ()
main = do
  need <- read <$> getLine :: IO Int
  result <- pure $ dfs [] [] 0 need

  print $ length result
  printList result

  
  
