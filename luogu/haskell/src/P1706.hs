module P1706 where

import Data.List (delete)

permutation :: [Int] -> [[Int]]
permutation [] = [[]]
permutation xs = [x:y | x <- xs, y <- permutation (delete x xs)]
-- foldr (\i x -> ((i:) <$> permutation (delete i xs)) ++ x) [] xs

printArr :: [[Int]] -> IO ()
printArr [] = return ()
printArr (x:xs) = do
    foldr (\i m -> (putStr $ "    " ++ show i) >> m) (return ()) x
    putStrLn ""
    printArr xs

main :: IO ()
main = do
    n <- read <$> getLine

    printArr $ permutation [1..n]

    return ()