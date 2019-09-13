module P1478 where
    import Data.List (sortBy)

    type Height = Int
    type Force = Int

    pick :: Height -> Force -> [(Height, Force)] -> Int
    pick _ _ [] = 0
    pick h f ((nh, nf):as)
        | h < nh = pick h f as
        | f < nf = 0
        | otherwise = 1 + pick h (f - nf) as

    readApples :: Int -> IO [(Height, Force)]
    readApples 0 = return []
    readApples n = do
        [nh, nf] <- map read . words <$> getLine

        ((nh, nf):) <$> readApples (n - 1)

    main :: IO ()
    main = do
        [ac, fs] <- map read . words <$> getLine :: IO [Int]
        [h, l] <- map read . words <$> getLine :: IO [Int]
        apples <- sortBy (\(_, a) (_, b) -> compare a b) <$> readApples ac

        print $ pick (h + l) fs apples

        return ()