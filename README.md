# M5stickCceilinglightIR

M5StickC x IR x Ceiling Light control



# M5StickC の赤外線端子からシーリングライトへコマンド信号を送るスケッチ

M5StickCからシーリングライトをON/OFF/メモリ２ボタンをトグル信号送信するスケッチです。

リモコンコマンドをアナライザ、オシロ等で波形を調べてから、スケッチに書き込みました。

受信モジュールがある方はIRremoteESP8266やIRRC32 の方が便利かもしれません。

このスケッチは、特にライブラリ追加は必要ありません。M5StickC環境だけです。

Ｔ値は、私の東芝シーリングライトに合わせた値に変えましたが、通常は562usec のようです（ＮＥＣリモコンコマンド規格、末尾ＵＲＬ参照）

M5StickC の赤外線端子は出力が弱いので、よく近づけて動作確認してください。

# 動作の様子

https://twitter.com/devemin/status/1251907084859224066

https://twitter.com/devemin/status/1251153219574657025?s=20


# テスト環境　東芝

https://twitter.com/devemin/status/1251153219574657025?s=20

東芝LEDシーリングライト LEDH94054-LC

リモコン FRC-194T(W)

# リモコン解析の様子

https://twitter.com/devemin/status/1251048008440938496?s=20

# 参考

http://elm-chan.org/docs/ir_format.html

https://blog.goo.ne.jp/jh7ubc/e/4740cd8da9def6fafad48f0745359371

https://www.mgo-tec.com/blog-entry-ledc-pwm-arduino-esp32.html

# MIT Liscense
