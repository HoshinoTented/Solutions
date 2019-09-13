module P4136 where

main :: IO ()
main = do
  n <- read <$> getLine

  if n == 0 then putStrLn "" else
    do
      putStrLn $ if even n then "Alice" else "Bob"
      main
      
  

