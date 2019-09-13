module P3742 where
    f :: String -> String -> String
    f [] [] = []
    f (x:xs) (y:ys)
        | x < y = []
        | otherwise = f' $ if x == y then x else y
        where
            f' x
                | xs == [] = x : []
                | f xs ys == [] = []
                | otherwise = x : f xs ys