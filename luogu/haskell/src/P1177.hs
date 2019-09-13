module P1177 where

mergeSort :: [Int] -> [Int]
mergeSort xs@(x:[]) = xs
mergeSort xs = merge (mergeSort $ fst parts) (mergeSort $ snd parts)
  where
    mid = length xs `div` 2
    parts = splitAt mid xs
    
merge :: [Int] -> [Int] -> [Int]
merge [] ys = ys
merge xs [] = xs
merge xl@(x:xs) yl@(y:ys) = if x < y then x : merge xs yl else y : merge xl ys

main :: IO ()
main = do
  n <- getLine
  ns <- (map read . words) <$> getLine

  putStrLn $ foldr (\x l -> show x ++ " " ++ l) "" $ mergeSort ns
