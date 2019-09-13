module P1028 where

import qualified Data.Vector.Mutable as MV
import Control.Applicative

search :: MV.IOVector Int -> Int -> IO Int
search _ 0 = return 0
search _ 1 = return 1
search v i = cache >>= \c ->
  if c /= -1 then return c else do
    c <- count
    MV.write v i c
    return c
  where
    cache = MV.read v i
    count = sequence [search v x | x <- [1 .. div i 2]] >>= return . (+1) . sum

main :: IO ()
main = do
  n <- read <$> getLine
  v <- MV.new (n + 1)

  foldr (\i m -> m >>= (const $ MV.write v i (-1))) (return ()) [0..n]

  print =<< (search v n)
  
  
  return ()
