class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        mapping = dict(zip(heights, names))
        sorted_keys = sorted(mapping.keys(), reverse=True)
        sort_mapping = {key: mapping[key] for key in sorted_keys}

        res = []

        for i in sort_mapping:
            res.append(sort_mapping[i])

        return res