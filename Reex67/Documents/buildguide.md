# HOOK69 ビルドガイド
## はじめに
このたびはご購入いただきありがとうございます。<br>
本製品は組み立てが必要なキットです。<br>

HOOK69はTK様([@tnkzm_tk](https://twitter.com/tnkzm_tk))のアイディアを元に液晶タブレット上面に設置して使用することに主眼を置いたキーボードです。<br>
使用するキーキャップについては[キーレイアウト](http://www.keyboard-layout-editor.com/##@@=Esc&=%E5%8D%8A%E8%A7%92%2F%2F%0A%0A%0A%0A%0A%0A%E5%85%A8%E8%A7%92&=Q&=W&=E&=R&=T&=Y&=Space&=U&=I&=O&=P&=%60%0A%0A%0A%0A%0A%0A%2F@&=%7B%0A%0A%0A%0A%0A%0A%5B&=WIN&=BS&=!%0A%0A%0A%0A%0A%0A1&=%E2%80%9D%0A%0A%0A%0A%0A%0A2&=%23%0A%0A%0A%0A%0A%0A3&=0&=%2F=%0A%0A%0A%0A%0A%0A-&=~%0A%0A%0A%0A%0A%0A%5E&_x:0.75%3B&=Rotary%0A%0A%0A%0A%0A%0APush%3B&@_a:7%3B&=&_x:-1%3B&=&_x:-1&a:4%3B&=TAB&=Shift&=A&=S&=D&=F&=G&=H&=Space&=J&=K&=L&=+%0A%0A%0A%0A%0A%0A%2F%3B&=*%0A%0A%0A%0A%0A%0A%2F:&=%7D%0A%0A%0A%0A%0A%0A%5D&=Shift&=Enter&=$%0A%0A%0A%0A%0A%0A4&=%25%0A%0A%0A%0A%0A%0A5&=%2F&%0A%0A%0A%0A%0A%0A6&_a:7%3B&=&_a:4%3B&=%E2%86%91&_a:7%3B&=&_x:0.75&a:4%3B&=Rotary%0A%0A%0A%0A%0A%0AUp%3B&@=CAPS&=Ctrl&=Alt&=Z&=X&=C&=V&=B&=Space&=N&=M&=%3C%0A%0A%0A%0A%0A%0A,&=%3E%0A%0A%0A%0A%0A%0A.&=%3F%0A%0A%0A%0A%0A%0A%2F%2F&=%2F_%0A%0A%0A%0A%0A%0A%5C&=Fn&=Ctrl&=%E2%80%99%0A%0A%0A%0A%0A%0A7&=(%0A%0A%0A%0A%0A%0A8&=)%0A%0A%0A%0A%0A%0A9&=%E2%86%90&=%E2%86%93&=%E2%86%92&_x:0.75%3B&=Rotary%0A%0A%0A%0A%0A%0ADown)を確認してください。<br>

写真は作成見本であり商品内容と同一ではありません。<br>
また仕様は予告なく変更されることがあります。<br>

ファームウェアに[qmk_firmware](https://github.com/qmk/qmk_firmware)を採用しています。<br>
QMKにHOOK69のコードはまだマージされていませんのでこの[ブランチ](https://github.com/kushima8/qmk_firmware/tree/hook69)を使用してください。<br>
動作確認の為に[HEXファイル](https://github.com/kushima8/HOOK69/tree/main/HEX)を用意しています。<br>

キット作成前にPro Microの書き込み環境の構築を行ってください。<br>
ファームウェアの書き込み環境の構築については下記のサリチル酸さんのサイトを参考にしてください。<br>
[（初心者編）自作キーボードにファームウェアを書き込む](https://salicylic-acid3.hatenablog.com/entry/qmk-toolbox)<br>

キー割り当ての変更方法などはご自身でお調べいただくようお願いします。<br>

GUIから簡単にキー割り当てを変更できる[VIA](https://caniusevia.com/)と[Remap](https://remap-keys.app/)に対応しております。<br>
ロータリーエンコーダの回転割り当ても含め、設定できますのでご活用ください。<br>
VIAとRemapについては下記のサリチル酸さんのサイトを参考にしてください。<br>
[（初心者編）VIAを使ってキーマップを書き換えよう](https://salicylic-acid3.hatenablog.com/entry/via-manual)<br>
[（初心者編）Remapを使ってキーマップを書き換えよう](https://salicylic-acid3.hatenablog.com/entry/remap-manual)<br>

以下の部品リストを参考に欠品がないか確認をお願いします。<br>

## 部品

### キットに付属しているもの

|名称|数量|備考|
|----|:---:|----|
|PCB|1枚|リバーシブル|
|トッププレート|1枚||
|ボトムプレート|1枚||
|M2 6mmスペーサー(ARB-2006E)|14個|丸型両メネジ|
|M2 4mmネジ|16本|
|M2 6mmネジ|12本|
|Kailh PCB ソケット(Kailh Choc V1用)|69個|
|ダイオード(1N4148W)|82個|
|タクトスイッチ|1個|
|ミニブックエンド|2個|

### 別途、購入が必ず必要なもの
以下の部品は別途購入してください。

|名称|数量|備考|
|----|:---:|----|
|キースイッチ(Cherry MX互換 or Kailh Choc V1)|69個|
|キーキャップ(Cherry MX互換 or Kailh Choc V2)|69個|
|Pro Micro|1個||
|コンスルーピンヘッダ|2個|キットに同梱されてない場合|
|プッシュスイッチ内蔵ロータリーエンコーダ(EC11/EC12互換 or EVQWGD001)|1個|
|ノブ|1個|EC11/EC12互換使用の場合のみ|

### オプション
以下の部品はオプション品です。
キーボードを光らせたいなどの場合のみ別途購入してください。

|名称|数量|備考|
|----|:---:|----|
|LEDチップ(YS-SK6812MINI-E)|1個|
|OLEDモジュール|1個|
|OLED用ピンソケット|1個|
|Kailh PCB ソケット(Cherry MX互換用)|69個|
|M2 3.5mmスペーサー(ARB-2003.5E)|12個|全キーCherry MX互換使用時のみ|
|M2 8mmネジ|12個|全キーCherry MX互換使用時のみ|

## 組み立て
※Daihuku Keyboardさんによるビルド動画があります。<br>
　本機を作成するにあたって参考になると思いますので是非御覧ください。<br>
　[![自作キーボード作ってみた HOOK69編](https://user-images.githubusercontent.com/58157342/204141216-9f6b336a-634c-4ee8-bc2e-d55b576e66ad.jpg)
](https://www.youtube.com/watch?v=qUh0zuOqxo4)<br>
※完成見本写真などではPro Microの接続位置を左端にしていますが、本機はリバーシブルPCBとなっております。<br>
　Pro Microを右端にして本機を使用したい場合は反転させて実装してください。<br>
　作成時にマスキングテープを使い表面と裏面がわかるようにしておくと作業ミスが少なくなります。<br>
　本ビルドガイドでは左側接続での作成での説明をしております。<br>
　右側接続で作成したい場合は適宜説明内容を読み替えてご覧ください。<br>
* 表面(左側接続)<br>
  ![001](https://user-images.githubusercontent.com/58157342/201514232-d5c59f57-ed02-4459-a088-942a7995d0e0.jpg)
* 裏面(左側接続)<br>
  ![002](https://user-images.githubusercontent.com/58157342/201514235-0f2b227f-cfa5-4988-a50a-2d0bb3c5f570.jpg)
* 表面(右側接続)<br>
  ![003](https://user-images.githubusercontent.com/58157342/201514235-0f2b227f-cfa5-4988-a50a-2d0bb3c5f570.jpg)
* 裏面(右側接続)<br>
  ![004](https://user-images.githubusercontent.com/58157342/201514232-d5c59f57-ed02-4459-a088-942a7995d0e0.jpg)
* 1.ヤスリがけ
  * 製造の都合上PCBにバリが存在します。<br>
  ![005](https://user-images.githubusercontent.com/58157342/201514394-0a8d4f42-bbfd-4f4d-a504-c75acbb8f76f.jpg)
  * バリが気になる場合は、この箇所を市販されている紙ヤスリなどで研磨してください。
* 2.Pro Microのはんだ付け
  * チップが載っている面が内側になるようにし、コンスルーピンヘッダを取り付けはんだ付けをしてください。
  * コンスルーピンヘッダには取り付け方向があるため気をつけてください。
  * [コンスルー - Self-Made Keyboards in Japan - ](https://scrapbox.io/self-made-kbds-ja/%E3%82%B3%E3%83%B3%E3%82%B9%E3%83%AB%E3%83%BC)<br>
  ![006](https://user-images.githubusercontent.com/58157342/89108152-21b31980-d471-11ea-9df6-11b106120852.JPG)
* 3.ファームウェアの書き込み
  * 左側接続で作成したい場合は、[HOOK69_default.hex](https://github.com/kushima8/HOOK69/tree/main/HEX)を指定してファームウェアを書き込んでください。
  * 右側接続で作成したい場合は、[HOOK69_right.hex](https://github.com/kushima8/HOOK69/tree/main/HEX)を指定してファームウェアを書き込んでください。
  * [REMAP](https://remap-keys.app/catalog/6cgxsudKJEdLPk9axw0j/firmware)でもファームウェアを書き込めるようにしております。
  * PCBのProMicro取り付け位置は表側の長方形のシルクで囲まれている箇所です。
* 4.LEDチップのはんだ付け(オプション)
  * 高い温度ではんだ付けを行うとLED破損の可能性がありますので、約270℃に設定してはんだ付けをするようにしてください。
  * 基板裏面のGのシルクのマークの位置にLEDの足が欠けている箇所が来るように設置し、はんだ付けを行ってください。
  * はんだ付けが完了したら一度Pro Microを取り付け、LEDが光るかどうかテストを行ってください。<br>
  ![007](https://user-images.githubusercontent.com/58157342/201514416-00f18cc6-650f-471a-a8d4-def12257ffe4.jpg)
  ![008](https://user-images.githubusercontent.com/58157342/201514417-2d174bed-f834-4977-be35-b14f98d3ea41.jpg)
* 5.ダイオードのはんだ付け
  * PCB裏面のダイオード取り付け箇所の片側に予めはんだを盛ります。<br>
  ![009](https://user-images.githubusercontent.com/58157342/201514465-0c7f6597-e0c4-4ea6-9222-379b3e3da465.jpg)
  ![010](https://user-images.githubusercontent.com/58157342/201514468-82664373-b9a4-45ce-bfda-e839a45e7e28.jpg)
  * その後、線が書いてある方を右(三角形の頂点の先に縦棒がある方)にセットします。
  * ダイオードをピンセットで持ちつつ、予めはんだを盛った箇所をはんだごてで加熱して片側だけはんだ付けを行います。<br>
  ![011](https://user-images.githubusercontent.com/58157342/201514470-b9e99ed9-ff6b-4049-b035-ad39a611c52a.jpg)
  * 片側のはんだ付けが完了後、もう片方もはんだ付けを行ってください。<br>
  ![012](https://user-images.githubusercontent.com/58157342/201514480-e4cd4ebc-f5ee-49eb-823f-6689afafb471.jpg)
* 6.Kailh PCB ソケット(MX用 or Kailh Choc V1用)のはんだ付け
  * PCB裏面のソケット取り付け箇所に予めはんだを盛ります。
  * 上穴がMX用で下穴がKailh Choc V1用です。<br>
  ![013](https://user-images.githubusercontent.com/58157342/201514683-85dcc180-e17d-4f30-b00d-e4caa7295757.jpg)
  * 中央の穴に干渉しないようにソケットをPCB裏面に設置しはんだ付けを行ってください。<br>
  ![014](https://user-images.githubusercontent.com/58157342/201514685-3445fbe2-e32e-47aa-bde9-aa802cb104ed.jpg)
  ![015](https://user-images.githubusercontent.com/58157342/201514689-b7c1ce86-df53-47af-bfaa-6c0b9961d78d.jpg)
  ![016](https://user-images.githubusercontent.com/58157342/201514691-8927c3b4-e4ff-45a5-a10a-d172bd1e0780.jpg)
* 7.タクトスイッチはんだ付け
  * PCB表面から取り付け、裏面からはんだ付けを行ってください。<br>
  ![017](https://user-images.githubusercontent.com/58157342/201514810-67ed621e-58e6-43ab-9091-5d23ed2a81cd.jpg)
  ![018](https://user-images.githubusercontent.com/58157342/201514812-5a9b7a27-fd62-4279-aa03-1b22fc56aed6.jpg)
* 8.OLEDの取り付け(オプション)
  * PCB裏面にあるジャンパ4箇所をショートさせてください。<br>
  ![019](https://user-images.githubusercontent.com/58157342/201514830-621a67a6-c5ee-4b5a-bf1d-95fa39ca6e7c.jpg)
  ![020](https://user-images.githubusercontent.com/58157342/201514831-cffb01e7-080c-4cbb-9d36-55acd93b7e79.jpg)
  * OLEDモジュールとピンヘッダのハンダ付けを行ってください。
  * ピンソケットをPCB表面から取り付け、裏面からはんだ付けを行ってください。<br>
  ![021](https://user-images.githubusercontent.com/58157342/201514854-8c95fdde-0e1a-44d1-b8f7-dc28d8b28c27.jpg)
  ![022](https://user-images.githubusercontent.com/58157342/201514860-6dca83f0-0c1e-4e46-8cf2-1e983f168538.jpg)
  ![023](https://user-images.githubusercontent.com/58157342/201514952-24e466ef-b7d6-4226-886d-004fbdc2f062.jpg)
* 9.ロータリーエンコーダ(EC11/EC12互換 or EVQWGD001)のはんだ付け
  * PCB表面からロータリーエンコーダを取り付け、裏面からはんだ付けを行ってください。
  * EVQWGD001の取り付けはフックを右側に、ピンを左側にして実装してください。
  * 長方形の穴にフック側を差し込み引っ掛けてからピンをPCB側に刺すと取り付け出来ます。<br>
  ![024](https://user-images.githubusercontent.com/58157342/201514910-76b17b16-dfad-45b7-9a8f-e7214d8f0898.jpg)
  ![025](https://user-images.githubusercontent.com/58157342/201514911-d80c2970-d8a2-43ae-b986-520339ebb92a.jpg)
  ![026](https://user-images.githubusercontent.com/58157342/201514914-e6eff74c-18e2-4f2a-a690-eb4a671e856f.jpg)
  ![027](https://user-images.githubusercontent.com/58157342/201514922-70686675-cc8e-4b1d-94e6-f30fd1e7194b.jpg)
  * EC11/EC12互換の場合は表面から取り付け裏面からはんだ付けを行ってください。
  * PCBの都合上固定がしにくくなっておりますので、しっかりと固定するようにはんだ付けをしてください。<br>
  ![028](https://user-images.githubusercontent.com/58157342/201514969-bccd1541-25fa-4d9b-ac70-2ea0589103a8.jpg)
  ![029](https://user-images.githubusercontent.com/58157342/201514971-e5686e6b-ce5b-41ba-aeb2-fa8d404e2097.jpg)
* 10.キースイッチの取り付け
  * トッププレートの穴にキースイッチを取り付けてください。
  * キースイッチがハマりにくい場合はヤスリなどを使いトッププレートの穴を削ってください。<br>
  ![030](https://user-images.githubusercontent.com/58157342/201515705-e91f95c2-5c8c-4b5a-9b88-55675464dfdd.jpg)
  ![031](https://user-images.githubusercontent.com/58157342/201515711-204082e6-411a-4051-8d18-b98dec6e40ee.jpg)
* 11.トッププレートの取り付け
  * PCBとネジ穴とキースイッチが合うようにトッププレートをPCB表面に設置。
  * ネジ穴下部にM2 6mmスペーサーを置き、上部からM2 6mmネジで固定してください。<br>
  ![032](https://user-images.githubusercontent.com/58157342/201515739-556a6662-d752-4803-916d-c6ed4f4ca922.jpg)
  ![033](https://user-images.githubusercontent.com/58157342/201515740-121c7ef6-8cac-4159-b978-9a7ea89f0a8b.jpg)
* 12.ProMicro下部スペーサー取り付け
  * ProMicro下部のネジ穴下部にM2 6mmスペーサーを設置し、上面からM2 4mmネジで固定してください。<br>
  ![034](https://user-images.githubusercontent.com/58157342/201515765-a789701e-4a21-4197-8f3d-5a24cb16ab11.jpg)
  ![035](https://user-images.githubusercontent.com/58157342/201515767-cc0c1925-9618-404d-bcd2-f32cc416dba3.jpg)
* 13.ボトムプレートの取り付け。
  * スペーサーとボトムプレートのネジ穴の位置を合わせ、M2 4mmネジで固定してください。<br>
  ![036](https://user-images.githubusercontent.com/58157342/201515783-844fe341-824e-4ae9-b851-2f6a7bb34412.jpg)
* 14.Pro Microの取り付け
  * Pro Microを取り付け、PCと接続しREMAPなどを用いてキースイッチとロータリーエンコーダの入力の確認を行ってください。
  * こちらが準備しているファームウェアの場合、ロータリーエンコーダの割当が空になっております。
  * REMAPなどで何かしらのキーを割当をしてから確認を行ってください。
  * PCBのProMicro取り付け位置は表側の長方形のシルクで囲まれている箇所です。
* 15.OLEDモジュールの取り付け(オプション)
  * OLEDモジュールを取り付け、PCと接続し、表示されることの確認を行ってください。
  * デフォルトではレイヤーとLEDの光度情報が表示されます。
* 16.つまみの取り付け(EC11/EC12互換使用の場合のみ)
  * つまみをロータリーエンコーダーに取り付けてください。
* 17.キーキャップの取り付け
  * キースイッチにキーキャップを取り付けてください。
  * 使用するキーキャップはすべて1Uのものになります。
* 18.ブックエンドの取り付け
  * 液タブの上面に取り付けるためにブックエンドを背面に取り付けます。
  * 付属のブックエンドを配置したい液タブ上面の形状に合わせて折り曲げます。<br>
  ![037](https://user-images.githubusercontent.com/58157342/201515040-f1c5532b-91ab-443b-96a2-05b214e00a33.jpg)
  ![038](https://user-images.githubusercontent.com/58157342/201515044-37e19a35-c16f-4ffb-9a21-d8dcd65fb2c9.jpg)
  ![039](https://user-images.githubusercontent.com/58157342/201515045-8ee43847-a1c7-4a05-86fb-dc21356845ca.jpg)
  ![040](https://user-images.githubusercontent.com/58157342/201515047-ed0a076c-9f26-4bf7-b57e-bb5ac02d6b99.jpg)
  * マスキングテープなどを使いキーボード本体に仮止めし、液タブ上面に設置します。<br>
  ![041](https://user-images.githubusercontent.com/58157342/202377845-bb420fcd-b653-4810-9516-9d805eb1857e.jpg)
　![042](https://user-images.githubusercontent.com/58157342/202377849-296d654f-d590-43b9-9705-ff169236decc.jpg)
　![043](https://user-images.githubusercontent.com/58157342/202377851-5f8c7a56-6fab-4621-b63c-c3a862497d6d.jpg)
  * 設置しブックエンドの配置に問題なければに仮止めを外し、両面テープなどで固定してください。
  * 固定する際はネジを避けるようにしてください。

組み立ての手順は、以上です。
