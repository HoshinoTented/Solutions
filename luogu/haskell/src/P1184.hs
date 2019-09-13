module P1184 where

main :: IO ()
main = do
  [n, m] <- (map read . words) <$> getLine :: IO [Int]
  
  canGo <- foldr (\x l -> pure (:) <*> getLine <*> l) (return []) [1..n]
  count <- foldr (\x l -> do
                     l' <- l
                     place <- getLine
                     return $ (if place `elem` canGo then (+1) else id) l')
                 (return 0) [1..m]

  print count

  return ()
  
