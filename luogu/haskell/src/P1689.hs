module P1689 where

-- TODO

data Symbol = Plus | Minus deriving (Show)
data Expr = Expr Int Symbol Int Int deriving (Show)

readIt' :: String -> IO String
readIt' xs = do
  c <- getChar

  if c == '\n' then return $ reverse xs else readIt' (if c == ' ' then xs else c : xs)

readIt :: IO String
readIt = readIt' []

parse :: String -> Expr
parse = undefined

main :: IO ()
main = do
  expr <- readIt

  return ()

  
