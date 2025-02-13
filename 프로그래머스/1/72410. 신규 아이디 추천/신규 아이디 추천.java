class Solution {
    public String solution(String new_id) {
        // 1단계: 대문자를 소문자로 치환
        new_id = new_id.toLowerCase();

        // 2단계: 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자 제거
        new_id = new_id.replaceAll("[^a-z0-9-_\\.]", "");

        // 3단계: 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
        new_id = new_id.replaceAll("[.]{2,}", ".");

        // 4단계: 마침표(.)가 처음이나 끝에 위치하면 제거
        if (new_id.length() > 0) {
            if (new_id.charAt(0) == '.') {
                new_id = new_id.substring(1);
            }
            if (new_id.length() > 0 && new_id.charAt(new_id.length() - 1) == '.') {
                new_id = new_id.substring(0, new_id.length() - 1);
            }
        }

        // 5단계: new_id가 빈 문자열이면 "a" 대입
        if (new_id.isEmpty()) {
            new_id = "a";
        }

        // 6단계: new_id의 길이가 16자 이상이면, 첫 15자만 남기고 나머지 제거
        if (new_id.length() > 15) {
            new_id = new_id.substring(0, 15);
            if (new_id.charAt(new_id.length() - 1) == '.') {
                new_id = new_id.substring(0, new_id.length() - 1);
            }
        }

        // 7단계: new_id 길이가 2자 이하이면, 마지막 문자를 반복하여 3자가 될 때까지 붙임
        while (new_id.length() < 3) {
            new_id += new_id.charAt(new_id.length() - 1);
        }

        return new_id;
    }
}
