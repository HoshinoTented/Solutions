module P2026 where

-- TODO

data Pos = Pos
  {
    x :: Int,
    y :: Int
  } deriving (Show)

type Persent = (Int, Int)

div' :: Int -> Int -> Persent
div' = (,)

times' :: Int -> Persent -> Persent
times' a (p, p') = (a * p' * p, p' * p')

minus' :: Int -> Persent -> Persent
minus' a (p, p') = (a * p' - p, p')

str' :: Persent -> String
str' (t, b) = if t `mod` b == 0 then show $ t `div` b else show t ++ "/" ++ show b

expr :: Pos -> Pos -> String
expr (Pos x1 y1) (Pos x2 y2) = let as = str' a in let ks = str' k in
  "y=" ++ (if as == "1" then "" else as) ++ "x" ++ (if ks == "0" then "" else "+" ++ ks)
  where
    a = (y1 - y2) `div'` (x1 - x2)
    k = y1 `minus'` (x1 `times'` a)

main :: IO ()
main = do
  [x1, y1] <- (map read . words) <$> getLine
  [x2, y2] <- (map read . words) <$> getLine

  putStrLn $ expr (Pos x1 y1) (Pos x2 y2)
