module P2669 where

-- Coin Count -> Day Count -> K -> Result
coin' :: Int -> Int -> Int -> Int
coin' _ _ 0 = 0
coin' c d k = if c == d then coin' (c + 1) 0 k else
  c + coin' c (d + 1) (k - 1)

coin :: Int -> Int
coin = coin' 1 0

main :: IO ()
main = do
  k <- read <$> getLine :: IO Int

  print $ coin k

  return ()
