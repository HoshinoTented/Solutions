module P1307 where

reverseNumber :: String -> String
reverseNumber ('-':str) = '-' : (reverseNumber str)
reverseNumber str = show num
  where
    num = read $ reverse str :: Int

main :: IO ()
main = do
  num <- getLine
  putStrLn $ reverseNumber num

  return ()
  
