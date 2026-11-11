# 색면화 작품별 음악 파일

작품 이야기·찾은 색·음악 콘셉트·상호작용 규칙은 [../plan/](../plan/) 기획 정리에 모아 두었습니다. 여덟 곡을 한 번에 들어 보는 플레이어도 거기에 있습니다. 기획 → 음악 생성 → 페이지 반영 순서로 고칩니다.

색면화 페이지의 「소리 → 소리 방식 → 작품별 음악 (ElevenLabs)」(기본값)을 고르면, 그림을 올릴 때 이 폴더의 같은 이름 파일을 반복 재생합니다. 파일이 없는 작품은 브라우저에서 만드는 「작품별 소리」로 대신합니다.

- 파일 이름: `cf1.mp3` ~ `cf8.mp3` (아래 표의 번호 = 재단 개요 표 순서 = 페이지 썸네일 순서 = 숫자 키 1~8. 2026-11-09 개요 순서로 다시 매김)
- 길이: 1분 안팎. 끝 3초와 다음 회차의 처음을 겹쳐서(크로스페이드) 이어 갑니다.
- 음량: 모두 -18 LUFS로 맞춤 (음량만 조정, 다이내믹은 그대로).
- 작품 이야기는 「함께누리예술전 미디어아트(색면화) 개요.hwpx」에서 가져왔습니다.

## 2026-11-11 다시 만듦 (3판, 지금 들어 있는 것)

2판은 앰비언트에 가까워 첫 15초가 조용했고 길이가 2분이었습니다. 3판은 **1분 안팎, 첫 1초부터 그 작품의 멜로디가 들리는 짧은 곡**입니다. 여덟 곡이 같은 악기 팔레트를 쓰고, 애장품 이야기는 선율의 성격으로 담았습니다. 음이 또렷하게 끊어져 나와서 화면의 소리 파장이 잘 보입니다. 2판 파일은 `../_candidates/prev_261109/`에 있습니다.

### 공통 꼬리말

> One of eight short pieces for one gallery installation, so all eight share one sound palette: felt piano, warm strings, soft mallets (marimba, celesta, glockenspiel) and plucked strings. Instrumental only, no vocals, no drum kit. This is a melodic miniature, not ambient music: the main melody begins within the first second, clear, simple and singable like a children's song, played with distinct note attacks. The melody is stated, answered once, and returns at the end. A gentle steady pulse runs underneath the whole piece so the rhythm can always be felt. Warm, close, bright mix with a short natural room reverb, no long ambient intro, no fade-in. About one minute long; it ends on a soft resolved chord that can loop straight back to the opening.

### 작품별 프롬프트 (앞부분)

| 번호 | 작품 | 프롬프트 |
|---|---|---|
| cf1 | 〈나이키 운동화〉 | 〈Basketball〉: a round ball that rolls anywhere, always in my room. D dorian, 84 BPM. From the first second, plucked nylon guitar and pizzicato strings play a bouncy, rolling melody that circles like a ball; marimba answers. A soft low thud lands on the downbeats like a ball bouncing, slowing a little at phrase ends. Playful, earthy, ochre and brown. |
| cf2 | 〈결혼식〉 | 〈Wedding〉: a white dress, a black tuxedo, a scene that makes my heart flutter. F major, 3/4 waltz, 72 BPM. From the first second, a music-box and celesta melody over felt piano in a gentle one-two-three; warm strings join for the answer and a few bright glockenspiel sparkles land on the high notes. Tender, fluttering, happy. |
| cf3 | 〈아빠〉 | 〈Dad〉: my dad always protected me, now I will protect him. E-flat major, 60 BPM. From the first second, a warm cello sings a simple strong melody over felt piano chords; a soft low heartbeat pulse on every beat. Each time the melody returns it starts one step higher, growing from being protected to protecting. Steady, strong, tender. |
| cf4 | 〈초코 쿠키〉 | 〈Chocolate Cookie〉: one sweet bite and I am full of energy. C lydian, 92 BPM. From the first second, marimba and kalimba play a bouncy, sweet, hopping melody with felt piano underneath; every few bars a quick rising glockenspiel arpeggio bursts up like a jolt of energy. Light, delicious, smiling. |
| cf5 | 〈동물〉 | 〈Animals〉: I love drawing animals, my home is full of animal figures. A major pentatonic, 88 BPM. From the first second, wooden marimba plays a curious tiptoeing melody with pizzicato strings; a small flute answers with short bird-call motifs, and woodblock taps mark the beat like little footsteps of toy animals. Playful, cozy. |
| cf6 | 〈나〉 | 〈Me〉: the most important thing in the world is me, I am precious. E major, 76 BPM. From the first second, felt piano plays a bright, confident, simple melody that keeps returning to its home note; a celesta doubles the melody an octave higher and a clear glockenspiel bell rings on the first beat of each bar; warm strings bloom underneath. Self-assured, clear, shining. |
| cf7 | 〈선생님〉 | 〈My Teacher〉: my kind teacher greets me every day; I draw her and write her letters. G major, 80 BPM. From the first second, felt piano plays a short greeting-like phrase, and each phrase is answered by a celesta echo one octave higher, like a letter and its reply. Light pizzicato strings keep a friendly walking pulse. Warm, kind, everyday comfort. |
| cf8 | 〈너부리〉 | 〈Neoburi, my plush friend〉: I cannot go one step without Neoburi; let us stay together. B-flat major, 82 BPM, walking pace. From the first second, marimba plays a cheerful walking melody with a plucked second voice always a third below, side by side; soft footstep-like taps on every beat. Warm, loyal, companionable. |

### 만드는 법

`POST /v1/music`, `model_id: music_v1`, `force_instrumental: true`, `music_length_ms: 60000`. 곡당 약 825 크레딧, 한 곡씩 15초 간격으로 보냅니다. 받은 파일은 앞뒤 무음(-48 dB)을 잘라 -18 LUFS로 맞추고 트루피크 -1.5 dB 리미터를 걸어 192k mp3로 저장합니다. 페이지는 끝 3초를 다음 회차의 처음과 겹쳐 반복합니다. 곡의 빠르기·박자를 바꾸면 `../index.html`의 `WORKS`에도 같은 값을 적습니다(빛 물결 주기가 거기서 나옵니다).

## 2026-11-09 (2판, 지난 것)

1판(11-03)은 곡마다 악기가 달라(오르골 왈츠, 로즈 건반, 마림바, 합창…) 그림을 바꿀 때 라디오 채널을 돌리는 느낌이었습니다. 2판은 여덟 곡이 **한 설치의 한 음색**으로 들리도록 공통 팔레트를 정하고, 그림이 올라와 띠가 하나씩 도착하는 첫 15초에 맞춰 음도 하나씩 들어오게 했습니다. 1판 파일은 `../_candidates/prev_261103/`에 그대로 있습니다.

### 공통 꼬리말 (모든 프롬프트 뒤에 붙임)

> Part of an eight-piece suite for one quiet gallery installation, so every piece shares the same sound palette: soft felt piano, warm sustained strings, a faint glassy mallet texture, and a hint of room air. No drums, no vocals, instrumental only. Very gentle dynamics, slow attacks, lots of silence and space, long natural reverb of a dark concrete room where coloured light particles drift slowly across a wall. Structure: begin almost silent, with single notes arriving one by one over the first fifteen seconds like coloured bands appearing on a wall; then settle into a slow, breathing, sustained passage that could continue forever; end as softly as it began, at the same low level, so the piece loops seamlessly.

### 작품별 프롬프트

| 번호 | 작품 | 이야기 | 프롬프트 (앞부분) |
|---|---|---|---|
| cf1 | 〈나이키 운동화〉 | 동그란 모양으로 어디든 굴러가는 농구공. 늘 내 방에 있어요 | 〈Basketball〉. D dorian, 70 BPM. Felt piano plays round, rolling arpeggios that keep circling like a ball rolling across a room; a muffled low thud now and then, slowing like a bounce coming to rest. Strings stay low and earthy, ochre and brown. |
| cf2 | 〈결혼식〉 | 하얀 드레스, 검정 턱시도. 생각만으로도 설레는 결혼식의 한 장면 | 〈Wedding〉. F major, 63 BPM, gentle 3/4 waltz feel implied by the piano, never heavy. Felt piano carries a tender, slightly shy melody; a few sparkling high celesta notes like light on a white dress; warm strings hold underneath. Quiet excitement held in. |
| cf3 | 〈아빠〉 | 힘든 순간에도 곁에서 든든하게 지켜준 아빠, 이제 내가 지켜줄게요 | 〈Dad〉. E-flat major, 56 BPM. Low cello and warm strings lead with the felt piano answering; a very soft slow heartbeat-like pulse far underneath. A simple melody that returns a little higher each time, growing from being protected to protecting. Steady, strong, tender. |
| cf4 | 〈초코 쿠키〉 | 달콤한 초코 쿠키 한입이면 힘이 불끈 솟아요 | 〈Chocolate Cookie〉. C lydian, 72 BPM. Felt piano with small bright mallet dots (soft marimba and kalimba) hopping above it; every so often a small rising arpeggio like a little burst of energy, then it relaxes again. Sweet, smiling, never hurried. |
| cf5 | 〈동물〉 | 그림 그리기를 좋아하고, 동물 피규어가 집에 한가득 | 〈Animals〉. A major pentatonic, 68 BPM. Felt piano with a wooden marimba close behind; tiny flute-like bird motifs appear now and then around the melody, curious and shy. A room full of small animal figures. |
| cf6 | 〈나〉 | 세상에서 제일 중요한 건 바로 나 자신, 내가 젤 소중해요 | 〈Me〉. E major, 60 BPM. Felt piano under a clear, airy, blooming string and glass pad that swells every few bars and settles; a calm, confident melody that returns to its root note. Self-affirming, bright, still. |
| cf7 | 〈선생님〉 | 늘 친절하게 맞아주는 선생님. 매일 그림을 그리고 편지를 써서 드려요 | 〈My Teacher〉. G major, 66 BPM, unhurried 4/4. Felt piano plays short greeting-like phrases, and each phrase is answered by a softer echo one octave higher, like a reply letter. Warm strings swell gently under the answers. Kind, everyday comfort. |
| cf8 | 〈너부리〉 | 너부리 없이는 어디든 한 발짝도 갈 수 없어요. 우리, 앞으로도 함께 하자 | 〈Neoburi, my plush friend〉. B-flat major, 66 BPM, walking pace. Felt piano melody with a second soft voice always a third below, walking side by side; very soft footstep-like taps far in the background. Warm, loyal companionship; never alone. |

### 만드는 법

ElevenLabs Music API(`POST /v1/music`, `model_id: music_v1`, `force_instrumental: true`, `music_length_ms: 120000`)에 위 프롬프트 + 공통 꼬리말을 보냅니다. 한 곡에 약 1,650 크레딧. 동시에 여러 곡을 보내면 429가 나므로 한 곡씩 20초 간격으로 보냅니다. 가끔 거의 무음인 결과(-70 LUFS)가 나오면 같은 프롬프트로 다시 만듭니다(11-09 〈결혼식〉 1회). 꼬리말의 "begin almost silent" 때문에 앞에 9~28초 무음이 붙어 나오기도 해서, 받은 파일은 `silencedetect`(-48 dB)로 앞뒤 무음을 잘라내고(앞 0.5초·뒤 1초만 남김) `ebur128`로 재서 `volume=`으로 -18 LUFS에 맞춘 뒤 트루피크 -1.5 dB 리미터를 걸어 192k mp3로 저장합니다. 그래서 곡 길이가 89~120초로 제각각입니다(〈동물〉이 89초로 가장 짧음). 〈나이키 운동화〉는 앞 무음이 24초라 "begin very quietly but audibly from the first second"로 바꿔 한 번 더 만든 것을 썼습니다.

캔버스 사진은 `../cf1.jpg` ~ `../cf8.jpg`(개요 순서). 〈너부리〉(cf8)는 2026-11-09에 8점을 한 번에 찍은 사진에서 잘라 넣었습니다 (검정·황토·크림·분홍 띠).
