SELECT COUNT(*) AS FISH_COUNT
FROM FISH_INFO, FISH_NAME_INFO
WHERE FISH_NAME_INFO.FISH_NAME IN('BASS','SNAPPER') AND FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
