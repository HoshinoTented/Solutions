module P1055 where

-- ISBN :: Current Index -> ISBN String -> Correct ISBN Code (Return Type)
isbn' :: Int -> String -> Int
isbn' 9 _ = 0
isbn' _ [] = error "hukanoudesu"
isbn' i ('-':str) = isbn' i str
isbn' i (c:str) = read [c] * (i + 1) + isbn' (i + 1) str

isbn :: String -> Int
isbn = isbn' 0

main :: IO ()
main = do
  xs <- init <$> getLine    -- 会读到换行符。。
  
  let
    i = (isbn xs) `mod` 11
    cIsbn = init xs ++ (if i == 10 then "X" else show i) in
    putStrLn $ if cIsbn == xs then "Right" else cIsbn
  
  return ()
  
