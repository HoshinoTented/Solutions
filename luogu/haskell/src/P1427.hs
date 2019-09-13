module P1427 where

main :: IO ()
main = do
  a <- words <$> getLine

  putStrLn $ drop 1 $ foldr (\x l -> if x == "0" then l else l ++ " " ++ x ) [] a
