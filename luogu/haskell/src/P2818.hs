module P2818 where

main :: IO ()
main = do
  a <- read <$> getLine
  b <- read <$> getLine

  let i = b `mod` a in
    print $ if i == 0 then a else i
