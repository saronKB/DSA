class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        output={}
        for path in paths:
            segments=path.split(' ')
            directory=segments[0]
            files=segments[1:]
            for info in files:
                start=info.index('(')
                end=info.index(')')
                filename=info[:start]
                content=info[start + 1:end]
                full_path=directory + '/' +filename
                if content not in output:
                    output[content]=[]
                output[content].append(full_path)
        result=[]
        for file_paths in output.values():
            if len(file_paths) >= 2:
                result.append(file_paths)
        return result