module P1618 where

import Data.List

type Triple = [Int]

check :: Int -> Triple -> Bool
check i t = if length xs > 9 then False else null $ foldr (\x l -> delete x l) ['1'..'9'] $ t >>= show . (i *)
  where
    xs = t >>= (show . (i *))

search' :: Int -> Triple -> [Int]
search' 999 _ = []
search' it t = if check it t then it : search' (it + 1) t else search' (it + 1) t

search :: Triple -> [Int]
search = search' 1

main :: IO ()
main = do
  t <- (map read . words) <$> getLine :: IO [Int]
  v <- return $ reverse $ search t

  if null v then putStrLn "No!!!" else
    foldr (\x m -> m >>= (const $ putStrLn (foldr (\y l -> show (x * y) ++ " " ++ l) [] t))) (return ()) v

  return ()
