# HiCo Thermal Table

Original thermal trip values and HiCo candidate values derived from the device's own tuning rules.

`original_max_trip_c` is the highest value found in the source artifact/section.
`hico_candidate_max_trip_c` is the highest value produced by HiCo's tuning policy for the same source scope. It is a candidate, not a measured or certified safe temperature.

Artifacts: **3255** · tuning rows: **7024** · tuning rows with candidate: **7024**

## Tuning table

| Vendor | Device | File | Section | Sensor | Original max °C | HiCo candidate max °C | Delta °C | Stock trips °C | HiCo trips °C |
|---|---|---|---|---|---:|---:|---:|---|---|
| xiaomi | `agate` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-k11r-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-k11r-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-huanji.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-k11r-huanji.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 41 43 44 45 | 44 46 48 49 50 |
| xiaomi | `agate` | `thermal-k11r-huanji.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 41 43 44 45 | 44 46 48 49 50 |
| xiaomi | `agate` | `thermal-k11r-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `agate` | `thermal-k11r-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `agate` | `thermal-k11r-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `agate` | `thermal-k11r-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-k11r-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-k11r-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-k11r-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 27 48 | 32 53 |
| xiaomi | `agate` | `thermal-k11r-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `agate` | `thermal-k11r-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `agate` | `thermal-k11r-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `agate` | `thermal-k11r-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-k11r-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-k11r-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `agate` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `agate` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `agate` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 43 45 48 | 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 27 48 | 32 53 |
| xiaomi | `agate` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `agate` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `agate` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `agate` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `agate` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `agate` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 39 41 43 45 48 | 42 44 46 48 50 53 |
| xiaomi | `alioth` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `alioth` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `alioth` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `alioth` | `thermal-india-normal.conf` | `INDIA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-india-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 48 | 18 51 |
| xiaomi | `alioth` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 48 | 18 51 |
| xiaomi | `alioth` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `alioth` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `alioth` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `alioth` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 27 48 | 30 51 |
| xiaomi | `alioth` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 27 48 | 30 51 |
| xiaomi | `alioth` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `alioth` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `alioth` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `andromeda` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `andromeda` | `thermal-arvr.conf` | `ARVR-SS-CPU4-SP0` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `andromeda` | `thermal-arvr.conf` | `ARVR-SS-CPU7-SP0` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP0` | `VIRTUAL-SENSOR` | 39.5 | 45.5 | 6 | 39.5 | 45.5 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP1` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 43 | 49 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP2` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 45 | 51 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP3` | `VIRTUAL-SENSOR` | 48 | 53.5 | 5.5 | 48 | 53.5 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP4` | `VIRTUAL-SENSOR` | 51 | 53.5 | 2.5 | 51 | 53.5 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP0` | `VIRTUAL-SENSOR` | 36.5 | 42.5 | 6 | 36.5 | 42.5 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP1` | `VIRTUAL-SENSOR` | 39.5 | 45.5 | 6 | 39.5 | 45.5 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP2` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 43 | 49 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP3` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 45 | 51 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP4` | `VIRTUAL-SENSOR` | 48 | 53.5 | 5.5 | 48 | 53.5 |
| xiaomi | `andromeda` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP5` | `VIRTUAL-SENSOR` | 51 | 53.5 | 2.5 | 51 | 53.5 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU4-SP0` | `VIRTUAL-SENSOR` | 39.5 | 45.5 | 6 | 39.5 | 45.5 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU4-SP1` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 43 | 49 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU4-SP2` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 45 | 51 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU4-SP3` | `VIRTUAL-SENSOR` | 48 | 53.5 | 5.5 | 48 | 53.5 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU4-SP4` | `VIRTUAL-SENSOR` | 51 | 53.5 | 2.5 | 51 | 53.5 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU7-SP0` | `VIRTUAL-SENSOR` | 36.5 | 42.5 | 6 | 36.5 | 42.5 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU7-SP1` | `VIRTUAL-SENSOR` | 39.5 | 45.5 | 6 | 39.5 | 45.5 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU7-SP2` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 43 | 49 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU7-SP3` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 45 | 51 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU7-SP4` | `VIRTUAL-SENSOR` | 48 | 53.5 | 5.5 | 48 | 53.5 |
| xiaomi | `andromeda` | `thermal-normal.conf` | `SS-CPU7-SP5` | `VIRTUAL-SENSOR` | 51 | 53.5 | 2.5 | 51 | 53.5 |
| xiaomi | `andromeda` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `andromeda` | `thermal-phone.conf` | `PHONE-SS-CPU4-SP0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `andromeda` | `thermal-phone.conf` | `PHONE-SS-CPU7-SP0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `angelica` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelica` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelica` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelica` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelica` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelica` | `thermal-chg-only.conf` | `SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelica` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelica` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelica` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `mtktsAP` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `angelica` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelica` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelicain` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelicain` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelicain` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelicain` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelicain` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelicain` | `thermal-chg-only.conf` | `SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelicain` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelicain` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelicain` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `mtktsAP` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `angelicain` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelicain` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelican` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelican` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelican` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelican` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelican` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelican` | `thermal-chg-only.conf` | `SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `angelican` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelican` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `angelican` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `mtktsAP` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `angelican` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `angelican` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `apollo` | `thermal-india-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `apollo` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `apollo` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `apollo` | `thermal-india-youtube.conf` | `INDIA-YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `apollo` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `apollo` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `apollo` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 27 48 | 30 51 |
| xiaomi | `apollo` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 27 48 | 30 51 |
| xiaomi | `apollo` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `apollo` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ares` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 42 43 44 | 45 47 48 49 |
| xiaomi | `ares` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 43 44 | 41 43 45 47 48 49 |
| xiaomi | `ares` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 42 43 44 | 45 47 48 49 |
| xiaomi | `ares` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 43 44 | 41 43 45 47 48 49 |
| xiaomi | `ares` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 39 40 41 42 43 43.5 44 | 44 45 46 47 48 48.5 49 |
| xiaomi | `ares` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 39 40 41 42 43 43.5 44 | 44 45 46 47 48 48.5 49 |
| xiaomi | `ares` | `thermal-india-4k.conf` | `INDIA-4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-india-4k.conf` | `INDIA-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `ares` | `thermal-india-4k.conf` | `INDIA-4K-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 39 41 44 47 | 44 46 49 52 |
| xiaomi | `ares` | `thermal-india-4k.conf` | `INDIA-4K-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 35 37 39 40 41 42 44 47 | 40 42 44 45 46 47 49 52 |
| xiaomi | `ares` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 38 40 43 44 | 43 45 48 49 |
| xiaomi | `ares` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 34 36 38 40 41 42 43 44 | 39 41 43 45 46 47 48 49 |
| xiaomi | `ares` | `thermal-india-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 39 40 41 42 43 43.5 44 | 44 45 46 47 48 48.5 49 |
| xiaomi | `ares` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 39 40 41 42 43 43.5 44 | 44 45 46 47 48 48.5 49 |
| xiaomi | `ares` | `thermal-india-mgame.conf` | `INDIA-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-india-mgame.conf` | `INDIA-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `ares` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 30 44 47 | 35 49 52 |
| xiaomi | `ares` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 38 40 41 44 47 | 43 45 46 49 52 |
| xiaomi | `ares` | `thermal-india-normal.conf` | `INDIA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `ares` | `thermal-india-normal.conf` | `INDIA-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 37 39 41 43 43.5 44 | 42 44 46 48 48.5 49 |
| xiaomi | `ares` | `thermal-india-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 37 39 41 43 43.5 44 | 42 44 46 48 48.5 49 |
| xiaomi | `ares` | `thermal-india-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 33 44 | 38 49 |
| xiaomi | `ares` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 33 44 | 38 49 |
| xiaomi | `ares` | `thermal-india-tgame.conf` | `INDIA-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-india-tgame.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `ares` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 44 47 | 49 52 |
| xiaomi | `ares` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 44 47 | 49 52 |
| xiaomi | `ares` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `ares` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 41 42 43 44 | 45 46 47 48 49 |
| xiaomi | `ares` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 37 39 40 41 42 44 | 42 44 45 46 47 49 |
| xiaomi | `ares` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `ares` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 30 47 | 35 52 |
| xiaomi | `ares` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 40 41 42 47 | 45 46 47 52 |
| xiaomi | `ares` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 39 40 41 42 43 43.5 44 | 44 45 46 47 48 48.5 49 |
| xiaomi | `ares` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 39 40 41 42 43 43.5 44 | 44 45 46 47 48 48.5 49 |
| xiaomi | `ares` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 33 44 | 38 49 |
| xiaomi | `ares` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 33 44 | 38 49 |
| xiaomi | `ares` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `ares` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `ares` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 44 47 | 49 52 |
| xiaomi | `ares` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 44 47 | 49 52 |
| xiaomi | `ares` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `ares` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 43 44 | 48 49 |
| xiaomi | `ares` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 41 42 43 44 | 45 46 47 48 49 |
| xiaomi | `ares` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 37 39 40 41 42 44 | 42 44 45 46 47 49 |
| xiaomi | `aristotle` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `aristotle` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `aristotle` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `aristotle` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 37 52 | 38 53 |
| xiaomi | `aristotle` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 37 52 | 38 53 |
| xiaomi | `aristotle` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `aristotle` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `aristotle` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `aristotle` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 25 37 39 41 43 44 45 47 48 | 29 41 43 45 47 48 49 51 52 |
| xiaomi | `aristotle` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 37 39 41 43 44 | 29 41 43 45 47 48 |
| xiaomi | `aristotle` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `aristotle` | `thermal-cgame.conf` | `CGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 15 45 50 | 16 46 51 |
| xiaomi | `aristotle` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `aristotle` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 15 43 46 | 17 45 48 |
| xiaomi | `aristotle` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `aristotle` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `aristotle` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 33 37 39 41 43 44 45 46 47 | 29 37 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 31 37 39 41 43 44 45 46 47 | 29 35 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `aristotle` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `aristotle` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 44 46 | 45 46 48 |
| xiaomi | `aristotle` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `aristotle` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `aristotle` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `aristotle` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `aristotle` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 35 47 | 36 48 |
| xiaomi | `aristotle` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 33 37 39 41 43 44 45 46 47 | 29 37 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `aristotle` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `aristotle` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 44 46 | 45 46 48 |
| xiaomi | `aristotle` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `aristotle` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `aristotle` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `aristotle` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `aristotle` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `aristotle` | `thermal-nolimits.conf` | `NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `aristotle` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 33 37 39 41 43 44 45 46 47 | 29 37 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `aristotle` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `aristotle` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `aristotle` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `aristotle` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `aristotle` | `thermal-per-huanji.conf` | `PER-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-per-huanji.conf` | `PER-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `aristotle` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `aristotle` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `aristotle` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `aristotle` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `aristotle` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `aristotle` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `aristotle` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43 44 45 46 47 | 39 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43 44 45 46 47 | 39 41 43 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `aristotle` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 27 45 48 | 31 49 52 |
| xiaomi | `aristotle` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 27 45 48 | 31 49 52 |
| xiaomi | `aristotle` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `aristotle` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `aristotle` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 31 35 37 41 43 44 45 46 47 | 19 35 39 41 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 31 35 37 41 43 44 45 46 47 | 19 35 39 41 45 47 48 49 50 51 |
| xiaomi | `aristotle` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 33 36 39 41 43 44 45 | 29 37 40 43 45 47 48 49 |
| xiaomi | `aristotle` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 33 36 39 41 43 44 45 | 29 37 40 43 45 47 48 49 |
| xiaomi | `aristotle` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `aristotle` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `aristotle` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `aristotle` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `atom` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `atom` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `atom` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `atom` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `atom` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `atom` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `atom` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `atom` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `atom` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `atom` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 20 51 | 22 53 |
| xiaomi | `atom` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `atom` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `atom` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `atom` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `atom` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `axolotl` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `quiet-therm-usr` | 43 | 48 | 5 | 41 43 | 46 48 |
| xiaomi | `axolotl` | `thermal-engine.conf` | `MONITOR_QUIET_THERM_HOTPLUG` | `quiet-therm-usr` | 48 | 53 | 5 | 46 48 | 51 53 |
| xiaomi | `axolotlaxie` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `quiet-therm-usr` | 43 | 48 | 5 | 41 43 | 46 48 |
| xiaomi | `axolotlaxie` | `thermal-engine.conf` | `MONITOR_QUIET_THERM_HOTPLUG` | `quiet-therm-usr` | 48 | 53 | 5 | 46 48 | 51 53 |
| xiaomi | `axolotlte` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `quiet-therm-usr` | 43 | 48 | 5 | 41 43 | 46 48 |
| xiaomi | `axolotlte` | `thermal-engine.conf` | `MONITOR_QUIET_THERM_HOTPLUG` | `quiet-therm-usr` | 48 | 53 | 5 | 46 48 | 51 53 |
| xiaomi | `begonia` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begonia` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 11 38 41 51 | 13 40 43 53 |
| xiaomi | `begonia` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `begonia` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `begonia` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 46 51 | 40 43 45 48 53 |
| xiaomi | `begonia` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 38 41 51 | 38 40 43 53 |
| xiaomi | `begonia` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `begonia` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begonia` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 43 44.5 46 51 | 45 46.5 48 53 |
| xiaomi | `begonia` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begonia` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 33 51 | 35 53 |
| xiaomi | `begonia` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `begonia` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begonia` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 38 41 51 | 38 40 43 53 |
| xiaomi | `begoniain` | `thermal-arvr.conf` | `INDIA-ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begoniain` | `thermal-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begoniain` | `thermal-chg-only.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 38 41 51 | 38 40 43 53 |
| xiaomi | `begoniain` | `thermal-nolimits.conf` | `INDIA-NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `begoniain` | `thermal-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begoniain` | `thermal-normal.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `begoniain` | `thermal-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begoniain` | `thermal-phone.conf` | `INDIA-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 33 51 | 35 53 |
| xiaomi | `begoniain` | `thermal-tgame.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begoniain` | `thermal-youtube.conf` | `INDIA-YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45 48 | 47 49 52 |
| xiaomi | `begoniain` | `thermal-youtube.conf` | `INDIA-YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 46 51 | 40 43 45 48 53 |
| xiaomi | `biloba` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `biloba` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `biloba` | `thermal-camera.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `biloba` | `thermal-camera.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `biloba` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `biloba` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `biloba` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `biloba` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 46 48 50 | 47 49 51 |
| xiaomi | `biloba` | `thermal-phone.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `biloba` | `thermal-phone.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `biloba` | `thermal-tgame.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `bomb` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `bomb` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `bomb` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `bomb` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `bomb` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `bomb` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `bomb` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `bomb` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `bomb` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `bomb` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `breeze` | `thermal-camera-india-demo.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 37 | 42 | 5 | 30 34 37 | 35 39 42 |
| xiaomi | `breeze` | `thermal-camera-india-demo.conf` | `INDIA-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 45.5 | 50.5 | 5 | 35 37 39 40 43.5 45.5 | 40 42 44 45 48.5 50.5 |
| xiaomi | `breeze` | `thermal-camera-india-demo.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 45.5 | 50.5 | 5 | 35 37 39 40 43.5 45.5 | 40 42 44 45 48.5 50.5 |
| xiaomi | `breeze` | `thermal-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 37 | 42 | 5 | 30 34 37 | 35 39 42 |
| xiaomi | `breeze` | `thermal-camera.conf` | `INDIA-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 45.5 | 50.5 | 5 | 35 37 39 40 43.5 45.5 | 40 42 44 45 48.5 50.5 |
| xiaomi | `breeze` | `thermal-camera.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 45.5 | 50.5 | 5 | 35 37 39 40 43.5 45.5 | 40 42 44 45 48.5 50.5 |
| xiaomi | `breeze` | `thermal-cclassvideo-india-demo.conf` | `INDIA-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `breeze` | `thermal-cclassvideo-india-demo.conf` | `INDIA-CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 29 31 33 35 37 39 41 43 | 34 36 38 40 42 44 46 48 |
| xiaomi | `breeze` | `thermal-cclassvideo-india-demo.conf` | `INDIA-CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 29 31 33 35 37 39 41 43 | 34 36 38 40 42 44 46 48 |
| xiaomi | `breeze` | `thermal-cclassvideo.conf` | `INDIA-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `breeze` | `thermal-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 29 31 33 35 37 39 41 43 | 34 36 38 40 42 44 46 48 |
| xiaomi | `breeze` | `thermal-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 29 31 33 35 37 39 41 43 | 34 36 38 40 42 44 46 48 |
| xiaomi | `breeze` | `thermal-cgame-india-demo.conf` | `INDIA-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `breeze` | `thermal-cgame-india-demo.conf` | `INDIA-CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-cgame-india-demo.conf` | `INDIA-CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-cgame.conf` | `INDIA-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `breeze` | `thermal-cgame.conf` | `INDIA-CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-cgame.conf` | `INDIA-CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-chg-only.conf` | `INDIA-CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-chg-only.conf` | `INDIA-CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-chg-only.conf` | `INDIA-CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-class0-india-demo.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 30 35 40 | 35 40 45 |
| xiaomi | `breeze` | `thermal-class0-india-demo.conf` | `INDIA-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-class0-india-demo.conf` | `INDIA-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 30 35 40 | 35 40 45 |
| xiaomi | `breeze` | `thermal-class0.conf` | `INDIA-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-class0.conf` | `INDIA-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-hp-game-india-demo.conf` | `INDIA-HP-GAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `breeze` | `thermal-hp-game-india-demo.conf` | `INDIA-HP-GAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `breeze` | `thermal-hp-game-india-demo.conf` | `INDIA-HP-GAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `breeze` | `thermal-hp-game-india-demo.conf` | `INDIA-HP-GAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-hp-game-india-demo.conf` | `INDIA-HP-GAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-hp-game.conf` | `INDIA-HP-GAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `breeze` | `thermal-hp-game.conf` | `INDIA-HP-GAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `breeze` | `thermal-hp-game.conf` | `INDIA-HP-GAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `breeze` | `thermal-hp-game.conf` | `INDIA-HP-GAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-hp-game.conf` | `INDIA-HP-GAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `breeze` | `thermal-hp-normal-india-demo.conf` | `INDIA-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `breeze` | `thermal-hp-normal-india-demo.conf` | `INDIA-HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `breeze` | `thermal-hp-normal-india-demo.conf` | `INDIA-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-hp-normal-india-demo.conf` | `INDIA-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 31 33 35 37 39 41 43 45 | 36 38 40 42 44 46 48 50 |
| xiaomi | `breeze` | `thermal-hp-normal-india-demo.conf` | `INDIA-HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 31 33 35 37 39 41 43 45 | 36 38 40 42 44 46 48 50 |
| xiaomi | `breeze` | `thermal-hp-normal.conf` | `INDIA-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `breeze` | `thermal-hp-normal.conf` | `INDIA-HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `breeze` | `thermal-hp-normal.conf` | `INDIA-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 31 33 35 37 39 41 43 45 | 36 38 40 42 44 46 48 50 |
| xiaomi | `breeze` | `thermal-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 31 33 35 37 39 41 43 45 | 36 38 40 42 44 46 48 50 |
| xiaomi | `breeze` | `thermal-huanji-india-demo.conf` | `INDIA-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-huanji-india-demo.conf` | `INDIA-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 33 35 37 39 40 42 43 | 38 40 42 44 45 47 48 |
| xiaomi | `breeze` | `thermal-huanji-india-demo.conf` | `INDIA-HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 33 35 37 39 40 42 43 | 38 40 42 44 45 47 48 |
| xiaomi | `breeze` | `thermal-huanji.conf` | `INDIA-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-huanji.conf` | `INDIA-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 33 35 37 39 40 42 43 | 38 40 42 44 45 47 48 |
| xiaomi | `breeze` | `thermal-huanji.conf` | `INDIA-HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 33 35 37 39 40 42 43 | 38 40 42 44 45 47 48 |
| xiaomi | `breeze` | `thermal-india-demo.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-india-demo.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-india-demo.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-livestream-india-demo.conf` | `INDIA-LIVERSTRAM-MONITOR-GPU` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 30 36 42 | 35 41 47 |
| xiaomi | `breeze` | `thermal-livestream-india-demo.conf` | `INDIA-LIVERSTRAM-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 34 36 38 40 42 44 46 | 39 41 43 45 47 49 51 |
| xiaomi | `breeze` | `thermal-livestream-india-demo.conf` | `INDIA-LIVERSTRAM-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 34 36 38 40 42 44 46 | 39 41 43 45 47 49 51 |
| xiaomi | `breeze` | `thermal-livestream.conf` | `INDIA-LIVERSTRAM-MONITOR-GPU` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 30 36 42 | 35 41 47 |
| xiaomi | `breeze` | `thermal-livestream.conf` | `INDIA-LIVERSTRAM-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 34 36 38 40 42 44 46 | 39 41 43 45 47 49 51 |
| xiaomi | `breeze` | `thermal-livestream.conf` | `INDIA-LIVERSTRAM-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 34 36 38 40 42 44 46 | 39 41 43 45 47 49 51 |
| xiaomi | `breeze` | `thermal-mgame-india-demo.conf` | `INDIA-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `breeze` | `thermal-mgame-india-demo.conf` | `INDIA-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `breeze` | `thermal-mgame.conf` | `INDIA-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `breeze` | `thermal-mgame.conf` | `INDIA-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `breeze` | `thermal-navigation-india-demo.conf` | `INDIA-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-navigation-india-demo.conf` | `INDIA-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-navigation-india-demo.conf` | `INDIA-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-navigation.conf` | `INDIA-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-navigation.conf` | `INDIA-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-navigation.conf` | `INDIA-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-nolimits-india-demo.conf` | `INDIA-NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `breeze` | `thermal-nolimits.conf` | `INDIA-NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `breeze` | `thermal-normal-india-demo.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-normal-india-demo.conf` | `INDIA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-normal-india-demo.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `breeze` | `thermal-normal.conf` | `INDIA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-normal.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-phone-india-demo.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 41 44 47 | 44 47 50 |
| xiaomi | `breeze` | `thermal-phone-india-demo.conf` | `INDIA-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `breeze` | `thermal-phone-india-demo.conf` | `INDIA-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `breeze` | `thermal-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 41 44 47 | 44 47 50 |
| xiaomi | `breeze` | `thermal-phone.conf` | `INDIA-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `breeze` | `thermal-phone.conf` | `INDIA-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `breeze` | `thermal-tgame-india-demo.conf` | `INDIA-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `breeze` | `thermal-tgame-india-demo.conf` | `INDIA-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `breeze` | `thermal-tgame.conf` | `INDIA-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `breeze` | `thermal-tgame.conf` | `INDIA-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `breeze` | `thermal-video-india-demo.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 30 35 40 | 35 40 45 |
| xiaomi | `breeze` | `thermal-video-india-demo.conf` | `INDIA-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-video-india-demo.conf` | `INDIA-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 30 35 40 | 35 40 45 |
| xiaomi | `breeze` | `thermal-video.conf` | `INDIA-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-video.conf` | `INDIA-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 42 44 46 | 40 42 44 45 47 49 51 |
| xiaomi | `breeze` | `thermal-videochat-india-demo.conf` | `INDIA-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 30 35 40 | 35 40 45 |
| xiaomi | `breeze` | `thermal-videochat-india-demo.conf` | `INDIA-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-videochat-india-demo.conf` | `INDIA-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-videochat.conf` | `INDIA-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 30 35 40 | 35 40 45 |
| xiaomi | `breeze` | `thermal-videochat.conf` | `INDIA-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `breeze` | `thermal-videochat.conf` | `INDIA-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `camellia` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `camellia` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `camellia` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `camellia` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `camellia` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `camellia` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `camellia` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `camellia` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 42 44 46 | 44 46 48 |
| xiaomi | `camellia` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `camellia` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 42 44 46 | 44 46 48 |
| xiaomi | `camellia` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `camellia` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `camellia` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `camellia` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `camellia` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 48 | 44 46 53 |
| xiaomi | `camellia` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `camellia` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `camellia` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 41 43 45 48 | 46 48 50 53 |
| xiaomi | `camellia` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `camellia` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `camellia` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `cannon` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cannon` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `cannon` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannon` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannon` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannon` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannon` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cannon` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannon` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannon` | `thermal-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cannon` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `cannon` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannon` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannon` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannon` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannon` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannon` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannon` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 33 51 | 35 53 |
| xiaomi | `cannon` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cannon` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `cannon` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannon` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannong` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cannong` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `cannong` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannong` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannong` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannong` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannong` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cannong` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannong` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cannong` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannong` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 33 51 | 35 53 |
| xiaomi | `cannong` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cannong` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `cannong` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cannong` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 43 46 51 | 40 45 48 53 |
| xiaomi | `cas` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 48 | 33 51 |
| xiaomi | `cas` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 48 | 33 51 |
| xiaomi | `cattail` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `cattail` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `cattail` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `cattail` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `cattail` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `cattail` | `thermal-chg-only.conf` | `SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `cattail` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `cattail` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `cattail` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `mtktsAP` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `cattail` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `cattail` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `cepheus` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `quiet_therm` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `cepheus` | `thermal-arvr.conf` | `ARVR-SS-CPU4-SP0` | `quiet_therm` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `cepheus` | `thermal-arvr.conf` | `ARVR-SS-CPU7-SP0` | `quiet_therm` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `quiet_therm` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP0` | `quiet_therm` | 38 | 44 | 6 | 38 | 44 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP1` | `quiet_therm` | 41 | 47 | 6 | 41 | 47 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP2` | `quiet_therm` | 44 | 50 | 6 | 44 | 50 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU4-SP3` | `quiet_therm` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP0` | `quiet_therm` | 35 | 41 | 6 | 35 | 41 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP1` | `quiet_therm` | 38 | 44 | 6 | 38 | 44 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP2` | `quiet_therm` | 41 | 47 | 6 | 41 | 47 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP3` | `quiet_therm` | 44 | 50 | 6 | 44 | 50 |
| xiaomi | `cepheus` | `thermal-camera.conf` | `CAMERA-SS-CPU7-SP4` | `quiet_therm` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `MONITOR-GPU` | `quiet_therm` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU4-SP0` | `quiet_therm` | 38 | 44 | 6 | 38 | 44 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU4-SP1` | `quiet_therm` | 41 | 47 | 6 | 41 | 47 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU4-SP2` | `quiet_therm` | 44 | 50 | 6 | 44 | 50 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU4-SP3` | `quiet_therm` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU7-SP0` | `quiet_therm` | 35 | 41 | 6 | 35 | 41 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU7-SP1` | `quiet_therm` | 38 | 44 | 6 | 38 | 44 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU7-SP2` | `quiet_therm` | 41 | 47 | 6 | 41 | 47 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU7-SP3` | `quiet_therm` | 44 | 50 | 6 | 44 | 50 |
| xiaomi | `cepheus` | `thermal-normal.conf` | `SS-CPU7-SP4` | `quiet_therm` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cepheus` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `quiet_therm` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `cepheus` | `thermal-phone.conf` | `PHONE-SS-CPU4-SP0` | `quiet_therm` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `cepheus` | `thermal-phone.conf` | `PHONE-SS-CPU7-SP0` | `quiet_therm` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `cetus` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 23 45 | 26 48 |
| xiaomi | `cetus` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `cetus` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `cetus` | `thermal-chg-only.conf` | `CHG-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `cetus` | `thermal-chg-only.conf` | `CHG-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `cetus` | `thermal-class0-unfold.conf` | `CLASS0-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `cetus` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `cetus` | `thermal-mgame-unfold.conf` | `MGAME-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `cetus` | `thermal-mgame-unfold.conf` | `MGAME-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD-GAME` | 46 | 48 | 2 | 15 46 | 17 48 |
| xiaomi | `cetus` | `thermal-mgame-unfold.conf` | `MGAME-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD-GAME` | 46 | 48 | 2 | 15 46 | 17 48 |
| xiaomi | `cetus` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `cetus` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 15 46 | 17 48 |
| xiaomi | `cetus` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 15 46 | 17 48 |
| xiaomi | `cetus` | `thermal-navigation-unfold.conf` | `NAVIGATION-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-navigation-unfold.conf` | `NAVIGATION-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 15 35 37 39 41 43 45 | 18 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-navigation-unfold.conf` | `NAVIGATION-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 15 35 37 39 41 43 45 | 18 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `cetus` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `cetus` | `thermal-normal-unfold.conf` | `UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `cetus` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `cetus` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 23 45 | 26 48 |
| xiaomi | `cetus` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `cetus` | `thermal-per-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `cetus` | `thermal-per-class0-unfold.conf` | `CLASS0-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 41 42 43 45 48 | 18 40 42 44 45 46 48 51 |
| xiaomi | `cetus` | `thermal-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 41 42 43 45 48 | 18 40 42 44 45 46 48 51 |
| xiaomi | `cetus` | `thermal-per-navigation-unfold.conf` | `NAVIGATION-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-navigation-unfold.conf` | `NAVIGATION-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-per-navigation-unfold.conf` | `NAVIGATION-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `cetus` | `thermal-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `cetus` | `thermal-per-normal-unfold.conf` | `UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 39 41 42 43 45 48 | 28 42 44 45 46 48 51 |
| xiaomi | `cetus` | `thermal-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 39 41 42 43 45 48 | 28 42 44 45 46 48 51 |
| xiaomi | `cetus` | `thermal-per-video-unfold.conf` | `VIDEO-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-video-unfold.conf` | `VIDEO-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-per-video-unfold.conf` | `VIDEO-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `cetus` | `thermal-per-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `cetus` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `cetus` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 27 45 48 | 30 48 51 |
| xiaomi | `cetus` | `thermal-video-unfold.conf` | `VIDEO-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-video-unfold.conf` | `VIDEO-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 15 35 37 39 41 43 45 | 18 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-video-unfold.conf` | `VIDEO-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 48 | 3 | 15 35 37 39 41 43 45 | 18 38 40 42 44 46 48 |
| xiaomi | `cetus` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cetus` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `cetus` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `cezanne` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cezanne` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 52 | 2 | 37 39 40 41 42 43 45 50 | 39 41 42 43 44 45 47 52 |
| xiaomi | `cezanne` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cezanne` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `cezanne` | `thermal-camera.conf` | `CAMERA-SS-CPU3` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 40 42 51 | 44 46 55 |
| xiaomi | `cezanne` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 52 | 2 | 36 38 40 41 42 43 45 50 | 38 40 42 43 44 45 47 52 |
| xiaomi | `cezanne` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 38 43 46 51 | 42 47 50 55 |
| xiaomi | `cezanne` | `thermal-class0.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 52 | 2 | 15 40 41 42 43 45 50 | 17 42 43 44 45 47 52 |
| xiaomi | `cezanne` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cezanne` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 40 41 42 | 45 46 47 |
| xiaomi | `cezanne` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `cezanne` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 52 | 2 | 36 38 40 41 42 43 45 50 | 38 40 42 43 44 45 47 52 |
| xiaomi | `cezanne` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `cezanne` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 33 51 | 37 55 |
| xiaomi | `cezanne` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `chopin` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `chopin` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `chopin` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 40 42 44 45 | 44 45 47 49 50 |
| xiaomi | `chopin` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 36 38 39 40 41 43 45 | 38 40 41 42 43 45 47 |
| xiaomi | `chopin` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `chopin` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `chopin` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 39 40 42 44 45 | 20 44 45 47 49 50 |
| xiaomi | `chopin` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 15 39 40 41 43 45 | 17 41 42 43 45 47 |
| xiaomi | `chopin` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 38 43 46 51 | 42 47 50 55 |
| xiaomi | `chopin` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 53 | 54 | 1 | 53 | 54 |
| xiaomi | `chopin` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 15 39 40 42 44 | 20 44 45 47 49 |
| xiaomi | `chopin` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 15 28 32 34 35 37 41 43 44 | 18 31 35 37 38 40 44 46 47 |
| xiaomi | `chopin` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `chopin` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `chopin` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 44 | 47 49 |
| xiaomi | `chopin` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 42 44 | 45 47 |
| xiaomi | `chopin` | `thermal-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `chopin` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `chopin` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 15 39 40 42 44 | 20 44 45 47 49 |
| xiaomi | `chopin` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 15 39 40 41 43 44 | 18 42 43 44 46 47 |
| xiaomi | `chopin` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `chopin` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `chopin` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 15 39 40 42 44 | 20 44 45 47 49 |
| xiaomi | `chopin` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 15 39 40 41 43 44 | 18 42 43 44 46 47 |
| xiaomi | `chopin` | `thermal-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `chopin` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 44 46 48 | 49 51 53 |
| xiaomi | `chopin` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 41 43 45 47 48 | 46 48 50 52 53 |
| xiaomi | `chopin` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 41 43 45 47 | 46 48 50 52 |
| xiaomi | `chopin` | `thermal-per-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 52 | 54 | 2 | 52 | 54 |
| xiaomi | `chopin` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `chopin` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 41 43 45 47 | 46 48 50 52 |
| xiaomi | `chopin` | `thermal-per-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 52 | 54 | 2 | 52 | 54 |
| xiaomi | `chopin` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 41 43 45 47 | 46 48 50 52 |
| xiaomi | `chopin` | `thermal-per-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 52 | 54 | 2 | 52 | 54 |
| xiaomi | `chopin` | `thermal-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 44 46 49 | 48 50 53 |
| xiaomi | `chopin` | `thermal-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 41 43 45 47 | 46 48 50 52 |
| xiaomi | `chopin` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 53 | 54 | 1 | 53 | 54 |
| xiaomi | `chopin` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `chopin` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 33 40 44 | 38 45 49 |
| xiaomi | `chopin` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 33 41 44 | 36 44 47 |
| xiaomi | `chopin` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `chopin` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `chopin` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 44 46 47 | 49 51 52 |
| xiaomi | `chopin` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `chopin` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `chopin` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 15 39 40 42 44 | 20 44 45 47 49 |
| xiaomi | `chopin` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 15 39 40 41 43 44 | 18 42 43 44 46 47 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 44 46 48 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-chg-only.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-nolimits.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 48 | 44 46 53 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `citrus` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `courbet` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `courbet` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `courbet` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `courbet` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `courbet` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `courbet` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 38 42 45 51 | 41 45 48 54 |
| xiaomi | `courbet` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `courbet` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `courbet` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `courbet` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 38 42 45 51 | 41 45 48 54 |
| xiaomi | `courbet` | `thermal-india-normal.conf` | `INDIA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `courbet` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `courbet` | `thermal-india-normal.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 45 48 51 | 39 41 45 48 51 54 |
| xiaomi | `courbet` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `courbet` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `courbet` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `courbet` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `courbet` | `thermal-normal.conf` | `MONITOR-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 42 44 45 51 | 44 45 47 48 54 |
| xiaomi | `courbet` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `courbet` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `courbet` | `thermal-phone.conf` | `PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `courbet` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 46 47.5 49 51 | 49 50.5 52 54 |
| xiaomi | `crux` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `crux` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `crux` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `crux` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `crux` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `crux` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `cupid` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `cupid` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `cupid` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `cupid` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `cupid` | `thermal-abnormal.conf` | `ABNORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-abnormal.conf` | `ABNORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-abnormal.conf` | `ABNORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 39 41 43 45 47 48 | 13 38 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-abnormal.conf` | `ABNORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 39 41 43 45 47 48 | 13 38 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 44 46 48 | 47 49 51 |
| xiaomi | `cupid` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `cupid` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `cupid` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `cupid` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `cupid` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `cupid` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `cupid` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 37 39 41 43 45 47 48 | 13 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 37 39 41 43 45 47 48 | 13 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 25 46 | 27 48 |
| xiaomi | `cupid` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `cupid` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `cupid` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 42 | 48 | 6 | 35 37 39 42 | 41 43 45 48 |
| xiaomi | `cupid` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42 | 48 | 6 | 25 42 | 31 48 |
| xiaomi | `cupid` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `cupid` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `cupid` | `thermal-iec-4k.conf` | `IEC-4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `cupid` | `thermal-iec-4k.conf` | `IEC-4K-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `cupid` | `thermal-iec-4k.conf` | `IEC-4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `cupid` | `thermal-iec-4k.conf` | `IEC-4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `cupid` | `thermal-iec-abnormal.conf` | `IEC-ABNORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-abnormal.conf` | `IEC-ABNORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-abnormal.conf` | `IEC-ABNORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 39 41 43 45 47 48 | 13 38 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-abnormal.conf` | `IEC-ABNORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 39 41 43 45 47 48 | 13 38 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-camera.conf` | `IEC-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `cupid` | `thermal-iec-camera.conf` | `IEC-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `cupid` | `thermal-iec-camera.conf` | `IEC-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `cupid` | `thermal-iec-camera.conf` | `IEC-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `cupid` | `thermal-iec-chg-only.conf` | `IEC-CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-chg-only.conf` | `IEC-CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-class0.conf` | `IEC-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-class0.conf` | `IEC-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-class0.conf` | `IEC-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 37 39 41 43 45 47 48 | 13 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-class0.conf` | `IEC-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 37 39 41 43 45 47 48 | 13 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-huanji.conf` | `IEC-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-huanji.conf` | `IEC-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 42 | 48 | 6 | 35 37 39 42 | 41 43 45 48 |
| xiaomi | `cupid` | `thermal-iec-huanji.conf` | `IEC-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42 | 48 | 6 | 25 42 | 31 48 |
| xiaomi | `cupid` | `thermal-iec-huanji.conf` | `IEC-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `cupid` | `thermal-iec-huanji.conf` | `IEC-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `cupid` | `thermal-iec-mgame.conf` | `IEC-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-mgame.conf` | `IEC-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `cupid` | `thermal-iec-mgame.conf` | `IEC-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `cupid` | `thermal-iec-mgame.conf` | `IEC-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `cupid` | `thermal-iec-mgame.conf` | `IEC-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `cupid` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-normal.conf` | `IEC-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-normal.conf` | `IEC-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-normal.conf` | `IEC-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 40 41 42 45 46 47 48 | 18 42 43 44 45 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-normal.conf` | `IEC-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 40 41 42 45 47 48 | 18 42 43 44 45 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `cupid` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 40 41 43 44 45 46 47 48 | 40 42 43 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 40 41 43 44 45 46 47 48 | 40 42 43 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `cupid` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 41 42 45 46 47 48 | 42 43 44 45 48 49 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 41 42 45 47 48 | 42 43 44 45 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `cupid` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-phone.conf` | `IEC-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-phone.conf` | `IEC-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-phone.conf` | `IEC-PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `cupid` | `thermal-iec-phone.conf` | `IEC-PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `cupid` | `thermal-iec-tgame.conf` | `IEC-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-tgame.conf` | `IEC-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `cupid` | `thermal-iec-tgame.conf` | `IEC-TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cupid` | `thermal-iec-tgame.conf` | `IEC-TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cupid` | `thermal-iec-video.conf` | `IEC-VIDEO-IEC-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-video.conf` | `IEC-VIDEO-IEC-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-video.conf` | `IEC-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-video.conf` | `IEC-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-videochat.conf` | `IEC-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-iec-videochat.conf` | `IEC-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-iec-videochat.conf` | `IEC-VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-iec-videochat.conf` | `IEC-VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `cupid` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `cupid` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `cupid` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `cupid` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 40 41 42 45 46 47 48 | 18 42 43 44 45 48 49 50 51 |
| xiaomi | `cupid` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 40 41 42 45 47 48 | 18 42 43 44 45 48 50 51 |
| xiaomi | `cupid` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `cupid` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 40 41 43 44 45 46 47 48 | 40 42 43 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 40 41 43 44 45 46 47 48 | 40 42 43 44 46 47 48 49 50 51 |
| xiaomi | `cupid` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `cupid` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 41 42 45 46 47 48 | 42 43 44 45 48 49 50 51 |
| xiaomi | `cupid` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 41 42 45 47 48 | 42 43 44 45 48 50 51 |
| xiaomi | `cupid` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `cupid` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `cupid` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `cupid` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `cupid` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cupid` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `cupid` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `cupid` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `cupid` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `cupid` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `cupid` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `curtana` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 43 | 48 | 5 | 36 37 38 40 41 42 43 | 41 42 43 45 46 47 48 |
| xiaomi | `curtana` | `thermal-engine-camera.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `curtana` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 43 | 48 | 5 | 36 37 38 40 41 42 43 | 41 42 43 45 46 47 48 |
| xiaomi | `curtana` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `dagu` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `dagu` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `dagu` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 46 48 | 38 40 42 44 46 48 49 51 |
| xiaomi | `dagu` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `dagu` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 44 45 47 48 | 41 42 44 46 47 48 50 51 |
| xiaomi | `dagu` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 40 41 43 44 45 48 | 41 42 43 44 46 47 48 51 |
| xiaomi | `dagu` | `thermal-chg-only.conf` | `CHG-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `dagu` | `thermal-chg-only.conf` | `CHG-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `dagu` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 15 45 | 18 48 |
| xiaomi | `dagu` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 44 45 47 48 | 41 42 44 46 47 48 50 51 |
| xiaomi | `dagu` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 40 41 43 44 45 48 | 41 42 43 44 46 47 48 51 |
| xiaomi | `dagu` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 35 37 39 40 41 41.5 41.8 | 41 43 45 46 47 47.5 47.8 |
| xiaomi | `dagu` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 35 37 39 40 41 41.5 41.8 | 41 43 45 46 47 47.5 47.8 |
| xiaomi | `dagu` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `dagu` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `dagu` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `dagu` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 40 45 | 38 43 48 |
| xiaomi | `dagu` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 44 45 47 48 | 41 42 44 46 47 48 50 51 |
| xiaomi | `dagu` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 40 41 43 44 45 48 | 41 42 43 44 46 47 48 51 |
| xiaomi | `dagu` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `dagu` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `dagu` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 45 | 38 48 |
| xiaomi | `dagu` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 44 45 47 48 | 41 42 44 46 47 48 50 51 |
| xiaomi | `dagu` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 40 41 43 44 45 48 | 41 42 43 44 46 47 48 51 |
| xiaomi | `dagu` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 15 45 | 18 48 |
| xiaomi | `dagu` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 38 39 41 43 44 45 47 | 39 42 43 45 47 48 49 51 |
| xiaomi | `dagu` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 40 41 43 44 45 48 | 41 42 43 44 46 47 48 51 |
| xiaomi | `dandelion` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `dandelion` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `dandelion` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `dandelion` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `dandelion` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `dandelion` | `thermal-chg-only.conf` | `SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `dandelion` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `dandelion` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `mtktsAP` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `dandelion` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `mtktsAP` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `dandelion` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `mtktsAP` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `dandelion` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `mtktsAP` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `davinci` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `davinci` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `davinci` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `davinci` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinci` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinci` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 35 36 37 43 44 51 | 37 38 39 45 46 53 |
| xiaomi | `davinci` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinci` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinci` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinci` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinci` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinci` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 39 43 51 | 41 45 53 |
| xiaomi | `davinci` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `davinci` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinci` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `davinci` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinci` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinci` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 37 40 51 | 39 42 53 |
| xiaomi | `davinciin` | `thermal-arvr.conf` | `INDIA-ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `davinciin` | `thermal-arvr.conf` | `INDIA-ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `davinciin` | `thermal-arvr.conf` | `INDIA-ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `davinciin` | `thermal-camera.conf` | `INDIA-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinciin` | `thermal-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinciin` | `thermal-camera.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 35 36 37 43 44 51 | 37 38 39 45 46 53 |
| xiaomi | `davinciin` | `thermal-chg-only.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinciin` | `thermal-nolimits.conf` | `INDIA-NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinciin` | `thermal-nolimits.conf` | `INDIA-NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinciin` | `thermal-normal.conf` | `INDIA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinciin` | `thermal-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinciin` | `thermal-normal.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 39 43 51 | 41 45 53 |
| xiaomi | `davinciin` | `thermal-phone.conf` | `INDIA-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `davinciin` | `thermal-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinciin` | `thermal-phone.conf` | `INDIA-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `davinciin` | `thermal-youtube.conf` | `INDIA-YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `davinciin` | `thermal-youtube.conf` | `INDIA-YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `davinciin` | `thermal-youtube.conf` | `INDIA-YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 37 40 51 | 39 42 53 |
| xiaomi | `diting` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `diting` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `diting` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-8k.conf` | `8K-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `diting` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `diting` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `diting` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `diting` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `diting` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `diting` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `diting` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `diting` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `diting` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `diting` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `diting` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `diting` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `diting` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `diting` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `diting` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `diting` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 43 | 49 | 6 | 43 | 49 |
| xiaomi | `diting` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `diting` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `diting` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `diting` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `diting` | `thermal-normal.conf` | `NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-normal.conf` | `NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `diting` | `thermal-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-normal.conf` | `NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `diting` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `diting` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `diting` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `diting` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `diting` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `diting` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `diting` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `diting` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `diting` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `diting` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 46.5 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `diting` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 46.5 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `diting` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `diting` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `diting` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `diting` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `diting` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `diting` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `diting` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `diting` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43.5 44.5 45.2 45.9 46.5 47.3 48 | 46.5 47.5 48.2 48.9 49.5 50.3 51 |
| xiaomi | `diting` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43.5 44.5 45.2 45.9 46.5 47.3 48 | 46.5 47.5 48.2 48.9 49.5 50.3 51 |
| xiaomi | `dizi` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `dizi` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 41 43 45 47 | 45 47 49 51 |
| xiaomi | `dizi` | `thermal-chg-only.conf` | `CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 41 43 45 46.5 47.5 | 44.5 46.5 48.5 50 51 |
| xiaomi | `dizi` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 43 45 46.5 47.5 | 42.5 44.5 46.5 48.5 50 51 |
| xiaomi | `dizi` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-demo.conf` | `DEMO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-demo.conf` | `DEMO-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 43 45 46.5 47.5 | 42.5 44.5 46.5 48.5 50 51 |
| xiaomi | `dizi` | `thermal-demo.conf` | `DEMO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `dizi` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `dizi` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 46 47 | 49 50 51 |
| xiaomi | `dizi` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 41 43 45 46 47 | 45 47 49 50 51 |
| xiaomi | `dizi` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 43 44 46 47 | 44 46 47 48 50 51 |
| xiaomi | `dizi` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `dizi` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `dizi` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 46 47 | 49 50 51 |
| xiaomi | `dizi` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 41 43 45 47 | 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `dizi` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `dizi` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 36 38 40 42 43 | 41 43 45 47 48 |
| xiaomi | `dizi` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 41 43 44 45 46 | 46 48 49 50 51 |
| xiaomi | `dizi` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 40 42 43 44 45 46 | 45 47 48 49 50 51 |
| xiaomi | `dizi` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 41 43 45 47 | 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-normal.conf` | `NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 43 45 46.5 47.5 | 42.5 44.5 46.5 48.5 50 51 |
| xiaomi | `dizi` | `thermal-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 41 43 44 45 46 | 46 48 49 50 51 |
| xiaomi | `dizi` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 40 42 43 44 45 46 | 45 47 48 49 50 51 |
| xiaomi | `dizi` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `dizi` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `dizi` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 43 45 | 42 44 46 48 50 |
| xiaomi | `dizi` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 38 40 42 44 45 | 43 45 47 49 50 |
| xiaomi | `earth` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `earth` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `earth` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `earth` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 39 41 48 | 43 45 52 |
| xiaomi | `elish` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 30 46 | 35 51 |
| xiaomi | `elish` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 30 46 | 35 51 |
| xiaomi | `elish` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `elish` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `elish` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `elish` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `evergo` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 36 38 40 42 44 47 | 41 43 45 47 49 52 |
| xiaomi | `evergo` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 36 38 40 42 44 47 | 41 43 45 47 49 52 |
| xiaomi | `evergo` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-class0.conf` | `WEIBO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-class0.conf` | `WEIBO-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergo` | `thermal-class0.conf` | `WEIBO-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergo` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergo` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergo` | `thermal-navigation.conf` | `NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-navigation.conf` | `NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergo` | `thermal-navigation.conf` | `NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergo` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergo` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergo` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergo` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 41 | 46 | 5 | 33 35 37 41 | 38 40 42 46 |
| xiaomi | `evergo` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 41 46 | 38 40 42 46 51 |
| xiaomi | `evergo` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergo` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergo` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergreen` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 36 38 40 42 44 47 | 41 43 45 47 49 52 |
| xiaomi | `evergreen` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 36 38 40 42 44 47 | 41 43 45 47 49 52 |
| xiaomi | `evergreen` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-class0.conf` | `WEIBO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-class0.conf` | `WEIBO-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergreen` | `thermal-class0.conf` | `WEIBO-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergreen` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergreen` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergreen` | `thermal-navigation.conf` | `NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-navigation.conf` | `NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergreen` | `thermal-navigation.conf` | `NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergreen` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `evergreen` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergreen` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `evergreen` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 41 | 46 | 5 | 33 35 37 41 | 38 40 42 46 |
| xiaomi | `evergreen` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 41 46 | 38 40 42 46 51 |
| xiaomi | `evergreen` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `evergreen` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `evergreen` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `excalibur` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 42 | 47 | 5 | 36 37 38 39 41 42 | 41 42 43 44 46 47 |
| xiaomi | `excalibur` | `thermal-engine-camera.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `excalibur` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 43 | 48 | 5 | 37 38 39 40 41 42 43 | 42 43 44 45 46 47 48 |
| xiaomi | `excalibur` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `fire` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `fire` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 43.5 | 47.5 | 4 | 34 36 42.5 43.5 | 38 40 46.5 47.5 |
| xiaomi | `fire` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 42.5 | 46.5 | 4 | 34 36 40 42.5 | 38 40 44 46.5 |
| xiaomi | `fire` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `fire` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 32 34 36 37 40 43 46.5 | 33.5 35.5 37.5 38.5 41.5 44.5 48 |
| xiaomi | `fire` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 47.5 | 1 | 32 34 36 37 40 43 46.5 | 33 35 37 38 41 44 47.5 |
| xiaomi | `fire` | `thermal-hp-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `fire` | `thermal-hp-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 35 39 40 41 42 43 46.5 | 36.5 40.5 41.5 42.5 43.5 44.5 48 |
| xiaomi | `fire` | `thermal-hp-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 47.5 | 1 | 35 39 40 41 42 43 46.5 | 36 40 41 42 43 44 47.5 |
| xiaomi | `fire` | `thermal-hp-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 48 | 0.5 | 38 40 42 44 45 47.5 | 38.5 40.5 42.5 44.5 45.5 48 |
| xiaomi | `fire` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `fire` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 35 39 40 41 42 43 46.5 | 36.5 40.5 41.5 42.5 43.5 44.5 48 |
| xiaomi | `fire` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 47.5 | 1 | 35 39 40 41 42 43 46.5 | 36 40 41 42 43 44 47.5 |
| xiaomi | `fire` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `fire` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `fire` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 32 34.5 36.5 40 | 36 38.5 40.5 44 |
| xiaomi | `fire` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 32 34.5 36.5 40 | 36 38.5 40.5 44 |
| xiaomi | `fire` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 48 | 0.5 | 38 40 42 44 45 47.5 | 38.5 40.5 42.5 44.5 45.5 48 |
| xiaomi | `fire` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `fire` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `fire` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 30 33.5 44 | 34 37.5 48 |
| xiaomi | `fire` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 47.5 | 3.5 | 30 33.5 44 | 33.5 37 47.5 |
| xiaomi | `fire` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `fire` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 35 39 40 41 42 43 46.5 | 36.5 40.5 41.5 42.5 43.5 44.5 48 |
| xiaomi | `fire` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 47.5 | 1 | 35 39 40 41 42 43 46.5 | 36 40 41 42 43 44 47.5 |
| xiaomi | `fire` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `fire` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `fire` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 30 32 35 37 43 | 34 36 39 41 47 |
| xiaomi | `fire` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 30 32 35 37 43 | 34 36 39 41 47 |
| xiaomi | `fire` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `fire` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 45 | 1 | 42 43 44 | 43 44 45 |
| xiaomi | `fire` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 42.5 | 46.5 | 4 | 34 36 40 42.5 | 38 40 44 46.5 |
| xiaomi | `fire` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 42.5 | 46.5 | 4 | 34 36 40 42.5 | 38 40 44 46.5 |
| xiaomi | `flame` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `flame` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `flame` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 37 39 41 43 45 | 40 42 44 46 48 50 |
| xiaomi | `flame` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 37 39 41 43 45 | 40 42 44 46 48 50 |
| xiaomi | `flame` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `flame` | `thermal-cgame.conf` | `CGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 46.5 | 49 | 2.5 | 46.5 | 49 |
| xiaomi | `flame` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 44 46 | 49 51 |
| xiaomi | `flame` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 40 41 42 45 | 42 43 45 46 47 50 |
| xiaomi | `flame` | `thermal-cgame.conf` | `CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 40 41 42 45 | 42 43 45 46 47 50 |
| xiaomi | `flame` | `thermal-chg-only.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 47 | 49 51 |
| xiaomi | `flame` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 47 | 49 51 |
| xiaomi | `flame` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `flame` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `flame` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `flame` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 37 39 41 43 45 | 40 42 44 46 48 50 |
| xiaomi | `flame` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 36 37 38 39 42 45 | 40 41 42 43 44 47 50 |
| xiaomi | `flame` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `flame` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `flame` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `flame` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `flame` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-livestream.conf` | `LIVESTREAM-MONITOR-CCC` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 43 | 48 |
| xiaomi | `flame` | `thermal-livestream.conf` | `LIVESTREAM-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `flame` | `thermal-livestream.conf` | `LIVESTREAM-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 42 45 | 42 44 46 47 50 |
| xiaomi | `flame` | `thermal-livestream.conf` | `LIVESTREAM-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 37 39 41 42 43 45 46 | 42 44 46 47 48 50 51 |
| xiaomi | `flame` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `flame` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 46.5 | 49 | 2.5 | 46.5 | 49 |
| xiaomi | `flame` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 44 46 | 49 51 |
| xiaomi | `flame` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 40 41 42 45 | 42 43 45 46 47 50 |
| xiaomi | `flame` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 40 41 42 45 | 42 43 45 46 47 50 |
| xiaomi | `flame` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `flame` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 43 45 | 42 44 46 48 50 |
| xiaomi | `flame` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 43 45 | 42 44 46 48 50 |
| xiaomi | `flame` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 47 | 49 51 |
| xiaomi | `flame` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 39 41 43 | 44 46 48 |
| xiaomi | `flame` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `flame` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `flame` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `flame` | `thermal-tgame.conf` | `TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 46.5 | 49 | 2.5 | 46.5 | 49 |
| xiaomi | `flame` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `flame` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 40 41 42 45 | 42 43 45 46 47 50 |
| xiaomi | `flame` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 40 41 42 45 | 42 43 45 46 47 50 |
| xiaomi | `flame` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 47 | 49 51 |
| xiaomi | `flame` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `flame` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `flame` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 37 39 41 43 45 | 40 42 44 46 48 50 |
| xiaomi | `flame` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 37 39 41 43 45 | 40 42 44 46 48 50 |
| xiaomi | `flare` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 44 46 48 | 46 48 50 |
| xiaomi | `flare` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 40.5 42.5 44.5 46.5 47.5 | 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 38 46 49 | 39 47 50 |
| xiaomi | `flare` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 44 46 48 | 46 48 50 |
| xiaomi | `flare` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `flare` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `flare` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 45 47 49 | 46 48 50 |
| xiaomi | `flare` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `flare` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 39 41 43 | 43 45 47 |
| xiaomi | `flare` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 39 41 43 45 47 | 40 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 39 41 43 45 47 | 40 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `flare` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 45 47 49 | 46 48 50 |
| xiaomi | `flare` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `flare` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 45 47 49 | 46 48 50 |
| xiaomi | `flare` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 42 44 46 48 | 42 45 47 49 51 |
| xiaomi | `flare` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 42 44 46 48 | 42 45 47 49 51 |
| xiaomi | `fleur` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 53 | 54 | 1 | 53 | 54 |
| xiaomi | `fleur` | `thermal-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 38 44 51 | 42 48 55 |
| xiaomi | `fleur` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 15 | 4 | 11 | 15 |
| xiaomi | `fleur` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 15 | 4 | 11 | 15 |
| xiaomi | `fleur` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 15 | 4 | 11 | 15 |
| xiaomi | `fleur` | `thermal-camera.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 42 44 46 | 46 48 50 |
| xiaomi | `fleur` | `thermal-camera.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 42.5 44.5 46.5 | 46.5 48.5 50.5 |
| xiaomi | `fleur` | `thermal-camera2.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `fleur` | `thermal-camera2.conf` | `SS-CPU0-1` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 51 | 55 |
| xiaomi | `fleur` | `thermal-camera2.conf` | `SS-CPU0-2` | `VIRTUAL-SENSOR` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `fleur` | `thermal-camera2.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 49 | 53 |
| xiaomi | `fleur` | `thermal-camera2.conf` | `SS-CPU6-1` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 51 | 55 |
| xiaomi | `fleur` | `thermal-camera2.conf` | `SS-CPU6-2` | `VIRTUAL-SENSOR` | 52 | 55 | 3 | 52 | 55 |
| xiaomi | `fleur` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `fleur` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `fleur` | `thermal-class0.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 38 39 41 51 | 42 43 45 55 |
| xiaomi | `fleur` | `thermal-class0.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 38.5 40 42 50 | 42.5 44 46 54 |
| xiaomi | `fleur` | `thermal-navigation.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 45.5 47.5 49 51 | 49.5 51.5 53 55 |
| xiaomi | `fleur` | `thermal-navigation.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 45 48 50 | 49 52 54 |
| xiaomi | `fleur` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 44.5 45.5 47.5 49 51 | 48.5 49.5 51.5 53 55 |
| xiaomi | `fleur` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 45 48 50 | 49 52 54 |
| xiaomi | `fleur` | `thermal-phone.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 40 | 44 |
| xiaomi | `fleur` | `thermal-phone.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `fleur` | `thermal-video.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51.5 | 4 | 45.5 47.5 | 49.5 51.5 |
| xiaomi | `fleur` | `thermal-video.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `fleur` | `thermal-videochat.conf` | `MONITOR-CPU3` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 42 | 46 |
| xiaomi | `fleur` | `thermal-videochat.conf` | `MONITOR-CPU5` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `fleur` | `thermal-videochat.conf` | `MONITOR-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `fleur` | `thermal-videochat.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51.5 | 4 | 38 41 44 45 47 47.5 | 42 45 48 49 51 51.5 |
| xiaomi | `fleur` | `thermal-videochat.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45.5 46 48 | 47 49.5 50 52 |
| xiaomi | `fog` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 37 43 50 | 40 46 53 |
| xiaomi | `fog` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 52 | 1 | 38 44 51 | 39 45 52 |
| xiaomi | `fog` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `fog` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `fog` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 12 | 17 | 5 | 12 | 17 |
| xiaomi | `fog` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `fog` | `thermal-camera.conf` | `Camera-SS-CPU0` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 44.5 45.5 47 48 49 | 48.5 49.5 51 52 53 |
| xiaomi | `fog` | `thermal-camera.conf` | `Camera-SS-CPU4` | `VIRTUAL-SENSOR` | 48.5 | 52 | 3.5 | 45 46 46.5 47.5 48.5 | 48.5 49.5 50 51 52 |
| xiaomi | `fog` | `thermal-camera.conf` | `MONITOR-CCC_CTRL-1` | `VIRTUAL-SENSOR` | 49.5 | 54.5 | 5 | 49.5 | 54.5 |
| xiaomi | `fog` | `thermal-camera.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `fog` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `fog` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `fog` | `thermal-nolimits.conf` | `NL-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `fog` | `thermal-nolimits.conf` | `NL-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `fog` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `fog` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `fog` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `fog` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 34 | 39 | 5 | 34 | 39 |
| xiaomi | `fog` | `thermal-tgame.conf` | `MONITOR-CCC_CTRL-1` | `VIRTUAL-SENSOR` | 49.5 | 54.5 | 5 | 49.5 | 54.5 |
| xiaomi | `fog` | `thermal-tgame.conf` | `Tgame-SS-CPU0` | `VIRTUAL-SENSOR` | 49.5 | 53 | 3.5 | 45 46.5 47.5 48.5 49.5 | 48.5 50 51 52 53 |
| xiaomi | `fog` | `thermal-tgame.conf` | `Tgame-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 52 | 3 | 44 45.5 47 48 49 | 47 48.5 50 51 52 |
| xiaomi | `fog` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `fog` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `fog` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 52 | 1 | 45 48 51 | 46 49 52 |
| xiaomi | `frost` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 52 | 2 | 37 43 50 | 39 45 52 |
| xiaomi | `frost` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 15 | 4 | 11 | 15 |
| xiaomi | `frost` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 15 | 4 | 11 | 15 |
| xiaomi | `frost` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 12 | 16 | 4 | 12 | 16 |
| xiaomi | `frost` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 11 | 15 | 4 | 11 | 15 |
| xiaomi | `frost` | `thermal-camera.conf` | `Camera-SS-CPU0` | `VIRTUAL-SENSOR` | 48.5 | 52 | 3.5 | 46 46.5 47.5 48.5 | 49.5 50 51 52 |
| xiaomi | `frost` | `thermal-camera.conf` | `Camera-SS-CPU1` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 45.5 47 48 49 | 49.5 51 52 53 |
| xiaomi | `frost` | `thermal-camera.conf` | `MONITOR-CCC_CTRL-1` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 49 | 53 |
| xiaomi | `frost` | `thermal-camera.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `frost` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `frost` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `frost` | `thermal-nolimits.conf` | `NL-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `frost` | `thermal-tgame.conf` | `Tgame-SS-CPU0` | `VIRTUAL-SENSOR` | 49 | 52 | 3 | 45.5 47 48 49 | 48.5 50 51 52 |
| xiaomi | `frost` | `thermal-tgame.conf` | `Tgame-SS-CPU1` | `VIRTUAL-SENSOR` | 49.5 | 53 | 3.5 | 46.5 47.5 48.5 49.5 | 50 51 52 53 |
| xiaomi | `gale` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 44 46 48 | 45 47 49 |
| xiaomi | `gale` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `gale` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `gale` | `thermal-chg-only.conf` | `CHG-ONLY-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 41 43 45 46 48 | 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 41 43 45 46 48 | 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 47 48 | 41 43 45 47 49 51 52 |
| xiaomi | `gale` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `gale` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `gale` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-huanji.conf` | `HUANJI-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `gale` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `gale` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 44 46 48 | 45 47 49 |
| xiaomi | `gale` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `gale` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `gale` | `thermal-normal.conf` | `MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `gale` | `thermal-phone.conf` | `PHONE-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 39 41 43 | 43 45 47 |
| xiaomi | `gale` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 46 48 | 39 43 45 47 50 52 |
| xiaomi | `gale` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 46 48 | 39 43 45 47 50 52 |
| xiaomi | `gale` | `thermal-tgame.conf` | `TGAME-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `gale` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `gale` | `thermal-video.conf` | `VIDEO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 47 48 | 41 43 45 47 49 51 52 |
| xiaomi | `gale` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 47 48 | 41 43 45 47 49 51 52 |
| xiaomi | `gale` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 49 | 50 |
| xiaomi | `gale` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 36 41 43 45 46 48 | 40 45 47 49 50 52 |
| xiaomi | `gale` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 36 41 43 45 46 48 | 40 45 47 49 50 52 |
| xiaomi | `garnet` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 36 38 40 41 42 43 45 48 | 28 39 41 43 44 45 46 48 51 |
| xiaomi | `garnet` | `thermal-512-4k.conf` | `512-4K-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-512-4k.conf` | `512-4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 36 38 40 41 42 43 45 48 | 28 39 41 43 44 45 46 48 51 |
| xiaomi | `garnet` | `thermal-512-camera.conf` | `512-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-512-camera.conf` | `512-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 45 48 | 28 38 40 42 44 48 51 |
| xiaomi | `garnet` | `thermal-512-cclassvideo.conf` | `512-CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `garnet` | `thermal-512-cgame.conf` | `512-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `garnet` | `thermal-512-cgame.conf` | `512-CGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 43 | 48 | 5 | 35 43 | 40 48 |
| xiaomi | `garnet` | `thermal-512-cgame.conf` | `512-CGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 25 45 46 | 30 50 51 |
| xiaomi | `garnet` | `thermal-512-class0.conf` | `512-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `garnet` | `thermal-512-dolbyvision.conf` | `512-DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-512-dolbyvision.conf` | `512-DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 41 43 44 45 | 30 40 42 46 48 49 50 |
| xiaomi | `garnet` | `thermal-512-highfps.conf` | `512-HIGHFPS-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 45 48 | 28 48 51 |
| xiaomi | `garnet` | `thermal-512-highfps.conf` | `512-HIGHFPS-SS-CPU4` | `VIRTUAL-SENSOR0` | 44 | 49 | 5 | 25 35 37 41 43 44 | 30 40 42 46 48 49 |
| xiaomi | `garnet` | `thermal-512-hp-mgame.conf` | `512-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `garnet` | `thermal-512-hp-mgame.conf` | `512-HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `garnet` | `thermal-512-hp-mgame.conf` | `512-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `garnet` | `thermal-512-hp-mgame.conf` | `512-HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `garnet` | `thermal-512-hp-mgame.conf` | `512-HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `garnet` | `thermal-512-hp-normal.conf` | `512-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `garnet` | `thermal-512-hp-normal.conf` | `512-HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `garnet` | `thermal-512-hp-normal.conf` | `512-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 45 46 | 45 47 48 |
| xiaomi | `garnet` | `thermal-512-hp-normal.conf` | `512-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 43 45 | 48 50 |
| xiaomi | `garnet` | `thermal-512-hp-normal.conf` | `512-HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 25 35 38 40 41 42 43 46 | 30 40 43 45 46 47 48 51 |
| xiaomi | `garnet` | `thermal-512-huanji.conf` | `512-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42 | 47 | 5 | 39 41 42 | 44 46 47 |
| xiaomi | `garnet` | `thermal-512-huanji.conf` | `512-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42 | 47 | 5 | 15 33 35 37 39 41 42 | 20 38 40 42 44 46 47 |
| xiaomi | `garnet` | `thermal-512-mgame.conf` | `512-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `garnet` | `thermal-512-mgame.conf` | `512-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `garnet` | `thermal-512-mgame.conf` | `512-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 44 45 | 49 50 |
| xiaomi | `garnet` | `thermal-512-navigation.conf` | `512-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-512-navigation.conf` | `512-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 39 41 43 45 | 30 40 42 44 46 48 50 |
| xiaomi | `garnet` | `thermal-512-normal.conf` | `512-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 38 40 41 42 45 48 | 28 38 41 43 44 45 48 51 |
| xiaomi | `garnet` | `thermal-512-per-class0.conf` | `512-PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 42 43 45 48 | 38 40 42 43 45 46 48 51 |
| xiaomi | `garnet` | `thermal-512-per-normal.conf` | `512-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 38 40 41 42 45 48 | 41 43 44 45 48 51 |
| xiaomi | `garnet` | `thermal-512-per-video.conf` | `512-PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-512-per-video.conf` | `512-PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 41 43 44 45 | 30 40 42 46 48 49 50 |
| xiaomi | `garnet` | `thermal-512-phone.conf` | `512-PHONE-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 35 37 39 45 | 40 42 44 50 |
| xiaomi | `garnet` | `thermal-512-phone.conf` | `512-PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 27 32 45 | 30 32 37 50 |
| xiaomi | `garnet` | `thermal-512-tgame.conf` | `512-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 45 46 | 47 48 |
| xiaomi | `garnet` | `thermal-512-tgame.conf` | `512-TGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 46 48 | 49 51 |
| xiaomi | `garnet` | `thermal-512-tgame.conf` | `512-TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `garnet` | `thermal-512-video.conf` | `512-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-512-video.conf` | `512-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 41 43 44 45 | 30 40 42 46 48 49 50 |
| xiaomi | `garnet` | `thermal-512-videochat.conf` | `512-VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 15 35 36 38 41 43 47 | 19 39 40 42 45 47 51 |
| xiaomi | `garnet` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 45 48 | 28 38 40 42 44 48 51 |
| xiaomi | `garnet` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `garnet` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `garnet` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 43 | 48 | 5 | 35 43 | 40 48 |
| xiaomi | `garnet` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 25 45 46 | 30 50 51 |
| xiaomi | `garnet` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 38 40 41 42 45 48 | 28 38 41 43 44 45 48 51 |
| xiaomi | `garnet` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `garnet` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 41 43 44 45 | 30 40 42 46 48 49 50 |
| xiaomi | `garnet` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 45 48 | 28 48 51 |
| xiaomi | `garnet` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU4` | `VIRTUAL-SENSOR0` | 44 | 49 | 5 | 25 35 37 41 43 44 | 30 40 42 46 48 49 |
| xiaomi | `garnet` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `garnet` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `garnet` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `garnet` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `garnet` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `garnet` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `garnet` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `garnet` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 45 46 | 45 47 48 |
| xiaomi | `garnet` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 43 45 | 48 50 |
| xiaomi | `garnet` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 25 35 38 40 41 42 43 46 | 30 40 43 45 46 47 48 51 |
| xiaomi | `garnet` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42 | 47 | 5 | 39 41 42 | 44 46 47 |
| xiaomi | `garnet` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42 | 47 | 5 | 15 33 35 37 39 41 42 | 20 38 40 42 44 46 47 |
| xiaomi | `garnet` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `garnet` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `garnet` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 44 45 | 49 50 |
| xiaomi | `garnet` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 39 41 43 45 | 30 40 42 44 46 48 50 |
| xiaomi | `garnet` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 38 40 41 42 45 48 | 28 38 41 43 44 45 48 51 |
| xiaomi | `garnet` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 42 43 45 48 | 38 40 42 43 45 46 48 51 |
| xiaomi | `garnet` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 38 40 41 42 45 48 | 41 43 44 45 48 51 |
| xiaomi | `garnet` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 41 43 44 45 | 30 40 42 46 48 49 50 |
| xiaomi | `garnet` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 35 37 39 45 | 40 42 44 50 |
| xiaomi | `garnet` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 27 32 45 | 30 32 37 50 |
| xiaomi | `garnet` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 45 46 | 47 48 |
| xiaomi | `garnet` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 46 48 | 49 51 |
| xiaomi | `garnet` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `garnet` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `garnet` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 50 | 5 | 25 35 37 41 43 44 45 | 30 40 42 46 48 49 50 |
| xiaomi | `garnet` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 15 35 36 38 41 43 47 | 19 39 40 42 45 47 51 |
| xiaomi | `gauguin` | `thermal-4k.conf` | `4k-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-4k.conf` | `4k-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `gauguin` | `thermal-4k.conf` | `4k-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 37 38 39 41 43 45 51 | 40 41 42 44 46 48 54 |
| xiaomi | `gauguin` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `gauguin` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `gauguin` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 37 38 39 41 43 45 51 | 40 41 42 44 46 48 54 |
| xiaomi | `gauguin` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `gauguin` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 37 38 39 41 43 45 51 | 40 41 42 44 46 48 54 |
| xiaomi | `gauguin` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `gauguin` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `gauguin` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 37 38 39 41 43 45 51 | 40 41 42 44 46 48 54 |
| xiaomi | `gauguin` | `thermal-india-normal.conf` | `INDIA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-india-normal.conf` | `INDIA-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `gauguin` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `gauguin` | `thermal-india-normal.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 37 38 39 41 43 45 48 | 42 43 44 46 48 50 53 |
| xiaomi | `gauguin` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-nolimits.conf` | `NL-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `gauguin` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 41 43 44 45 48 | 46 48 49 50 53 |
| xiaomi | `gauguin` | `thermal-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `gauguin` | `thermal-per-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 37 38 39 41 43 45 51 | 40 41 42 44 46 48 54 |
| xiaomi | `gauguin` | `thermal-per-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `gauguin` | `thermal-per-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 41 43 44 45 48 | 46 48 49 50 53 |
| xiaomi | `gauguin` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `gauguin` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `gauguin` | `thermal-phone.conf` | `PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `gauguin` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `gauguin` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `gauguin` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 46 47 | 51 52 |
| xiaomi | `ginkgo` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-adc` | 35 | 40 | 5 | 35 | 40 |
| xiaomi | `ginkgo` | `thermal-engine-camera.conf` | `HIGH_TEMP_STATE_flash` | `quiet-therm-adc` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `ginkgo` | `thermal-engine-camera.conf` | `LCD_MONITOR` | `backlight_therm` | 46 | 51 | 5 | 44 45 46 | 49 50 51 |
| xiaomi | `ginkgo` | `thermal-engine-camera.conf` | `MONITOR-CPU-HOTPLUG` | `quiet-therm-adc` | 50 | 55 | 5 | 47 50 | 52 55 |
| xiaomi | `ginkgo` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-adc` | 44 | 49 | 5 | 37.5 39.5 40 41 42 43 44 | 42.5 44.5 45 46 47 48 49 |
| xiaomi | `ginkgo` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `backlight_therm` | 46 | 51 | 5 | 44 45 46 | 49 50 51 |
| xiaomi | `ginkgo` | `thermal-engine-normal.conf` | `MONITOR-CPU-HOTPLUG` | `quiet-therm-adc` | 50 | 55 | 5 | 47 50 | 52 55 |
| xiaomi | `gold` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 37 | 42 | 5 | 30 34 37 | 35 39 42 |
| xiaomi | `gold` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 37 39 41 45 | 40 42 44 46 50 |
| xiaomi | `gold` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 37 39 41 45 | 40 42 44 46 50 |
| xiaomi | `gold` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMI` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `gold` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 29 31 33 35 37 39 41 43 45 46 | 34 36 38 40 42 44 46 48 50 51 |
| xiaomi | `gold` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `gold` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `gold` | `thermal-cgame.conf` | `CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `gold` | `thermal-chg-only.conf` | `CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `gold` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 25 35 37 39 41 43 45 46 | 30 40 42 44 46 48 50 51 |
| xiaomi | `gold` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 25 35 37 39 41 43 45 46 | 30 40 42 44 46 48 50 51 |
| xiaomi | `gold` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `gold` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 34 36 38 40 42 44 46 48 | 37 39 41 43 45 47 49 51 |
| xiaomi | `gold` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 34 36 38 40 42 44 46 48 | 37 39 41 43 45 47 49 51 |
| xiaomi | `gold` | `thermal-hp-game.conf` | `HP-GAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `gold` | `thermal-hp-game.conf` | `HP-GAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `gold` | `thermal-hp-game.conf` | `HP-GAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `gold` | `thermal-hp-game.conf` | `HP-GAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 43 44 45 | 48 49 50 |
| xiaomi | `gold` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `gold` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `gold` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 31 33 35 37 39 41 43 45 | 36 38 40 42 44 46 48 50 |
| xiaomi | `gold` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 31 33 35 37 39 41 43 45 | 36 38 40 42 44 46 48 50 |
| xiaomi | `gold` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `gold` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 29 33 35 38 40 42 | 34 38 40 43 45 47 |
| xiaomi | `gold` | `thermal-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 29 33 35 38 40 42 | 34 38 40 43 45 47 |
| xiaomi | `gold` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `gold` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 39 40 41 42 43 45 46 | 44 45 46 47 48 50 51 |
| xiaomi | `gold` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 39 40 41 42 43 45 46 | 44 45 46 47 48 50 51 |
| xiaomi | `gold` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `gold` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 29 31 33 35 37 39 41 43 45 | 34 36 38 40 42 44 46 48 50 |
| xiaomi | `gold` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 29 31 33 35 37 39 41 43 45 | 34 36 38 40 42 44 46 48 50 |
| xiaomi | `gold` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `gold` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 34 36 38 40 42 44 46 48 | 37 39 41 43 45 47 49 51 |
| xiaomi | `gold` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 34 36 38 40 42 44 46 48 | 37 39 41 43 45 47 49 51 |
| xiaomi | `gold` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 41 | 46 | 5 | 41 | 46 |
| xiaomi | `gold` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 37 | 42 | 5 | 25 31 37 | 30 36 42 |
| xiaomi | `gold` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 37 | 42 | 5 | 25 31 37 | 30 36 42 |
| xiaomi | `gold` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `gold` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 39 40 41 42 43 45 46 | 44 45 46 47 48 50 51 |
| xiaomi | `gold` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 39 40 41 42 43 45 46 | 44 45 46 47 48 50 51 |
| xiaomi | `gold` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 41 | 46 | 5 | 41 | 46 |
| xiaomi | `gold` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 34 36 38 40 42 44 46 | 39 41 43 45 47 49 51 |
| xiaomi | `gold` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 34 36 38 40 42 44 46 | 39 41 43 45 47 49 51 |
| xiaomi | `gold` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `gold` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 30 35 40 | 35 40 45 |
| xiaomi | `gold` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 29 31 33 35 37 39 41 43 45 | 34 36 38 40 42 44 46 48 50 |
| xiaomi | `gold` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 29 31 33 35 37 39 41 43 45 | 34 36 38 40 42 44 46 48 50 |
| xiaomi | `gram` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 42 | 47 | 5 | 36 37 38 39 41 42 | 41 42 43 44 46 47 |
| xiaomi | `gram` | `thermal-engine-camera.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `gram` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 43 | 48 | 5 | 37 38 39 40 41 42 43 | 42 43 44 45 46 47 48 |
| xiaomi | `gram` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `haydn` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `haydn` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `haydn` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-india-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 45 48 | 28 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 45 48 | 28 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-india-mgame.conf` | `INDIA-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `haydn` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `haydn` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `haydn` | `thermal-india-navigation.conf` | `INDIA-NAV-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-india-navigation.conf` | `INDIA-NAV-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-india-navigation.conf` | `INDIA-NAV-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 43 45 48 | 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-india-normal.conf` | `INDIA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 41 42 43 45 48 | 28 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-india-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 41 42 43 45 48 | 28 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-india-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 27 45 48 | 30 48 51 |
| xiaomi | `haydn` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 27 48 | 30 51 |
| xiaomi | `haydn` | `thermal-india-tgame.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `haydn` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `haydn` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `haydn` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 45 48 | 28 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 45 48 | 28 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `haydn` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `haydn` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `haydn` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `haydn` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `haydn` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-per-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `haydn` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 41 42 43 45 48 | 18 40 42 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 41 42 43 45 48 | 18 40 42 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `haydn` | `thermal-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `haydn` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 42 43 45 48 | 28 42 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 42 43 45 48 | 28 42 44 45 46 48 51 |
| xiaomi | `haydn` | `thermal-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `haydn` | `thermal-per-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `haydn` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 43 45 | 49 51 |
| xiaomi | `haydn` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 27 45 48 | 30 48 51 |
| xiaomi | `haydn` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 27 45 48 | 30 48 51 |
| xiaomi | `haydn` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `haydn` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `haydn` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `haydn` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `haydn` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `haydn` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `ido` | `thermal-engine.conf` | `CHARGING_MONITOR` | `pop_mem` | 45 | 50 | 5 | 43 45 | 48 50 |
| xiaomi | `ingres` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 44 46 48 | 47 49 51 |
| xiaomi | `ingres` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `ingres` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `ingres` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-chg-only.conf` | `CHG-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 42 45 46 47 48 | 28 38 40 42 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-chg-only.conf` | `CHG-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 42 45 46 47 48 | 28 38 40 42 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 25 46 | 27 48 |
| xiaomi | `ingres` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `ingres` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `ingres` | `thermal-hp-normal.conf` | `HP-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-hp-normal.conf` | `HP-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-hp-normal.conf` | `HP-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-hp-normal.conf` | `HP-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `ingres` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 43 | 48 | 5 | 15 39 41 43 | 20 44 46 48 |
| xiaomi | `ingres` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `ingres` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `ingres` | `thermal-india-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-india-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-india-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-india-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `ingres` | `thermal-india-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `ingres` | `thermal-india-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 43 | 48 | 5 | 15 39 41 43 | 20 44 46 48 |
| xiaomi | `ingres` | `thermal-india-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `ingres` | `thermal-india-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `ingres` | `thermal-india-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ingres` | `thermal-india-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ingres` | `thermal-india-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ingres` | `thermal-india-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 35 | 41 | 6 | 35 | 41 |
| xiaomi | `ingres` | `thermal-india-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-india-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-india-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `ingres` | `thermal-india-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-india-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-india-per-camera.conf` | `PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-camera.conf` | `PER-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-camera.conf` | `PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `ingres` | `thermal-india-per-camera.conf` | `PER-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `ingres` | `thermal-india-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-navigation.conf` | `PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-india-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-india-per-normal.conf` | `PER-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-per-normal.conf` | `PER-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `ingres` | `thermal-india-per-normal.conf` | `PER-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-normal.conf` | `PER-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-india-per-normal.conf` | `PER-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-india-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 41 43 45 48 | 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 41 43 45 48 | 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR0` | 30 | 36 | 6 | 30 | 36 |
| xiaomi | `ingres` | `thermal-india-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `ingres` | `thermal-india-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `ingres` | `thermal-india-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `ingres` | `thermal-india-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `ingres` | `thermal-india-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 35 37 39 40 41 43 45 48 | 18 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 40 41 43 45 48 | 28 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-india-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-india-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-india-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-india-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-india-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `ingres` | `thermal-india-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `ingres` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ingres` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 36 40 42 43.5 45 | 42 46 48 49.5 51 |
| xiaomi | `ingres` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 36 40 42 43.5 45 | 42 46 48 49.5 51 |
| xiaomi | `ingres` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 35 | 41 | 6 | 35 | 41 |
| xiaomi | `ingres` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `ingres` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `ingres` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `ingres` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `ingres` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-per-normal.conf` | `PER-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-per-normal.conf` | `PER-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `ingres` | `thermal-per-normal.conf` | `PER-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-normal.conf` | `PER-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-per-normal.conf` | `PER-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `ingres` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 41 43 45 48 | 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 41 43 45 48 | 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR0` | 30 | 36 | 6 | 30 | 36 |
| xiaomi | `ingres` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `ingres` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `ingres` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 44 44.8 45.6 46.4 47.2 48 | 47 47.8 48.6 49.4 50.2 51 |
| xiaomi | `ingres` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 44 44.8 45.6 46.4 47.2 48 | 47 47.8 48.6 49.4 50.2 51 |
| xiaomi | `ingres` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 35 37 39 40 41 43 45 48 | 18 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 40 41 43 45 48 | 28 38 40 42 43 44 46 48 51 |
| xiaomi | `ingres` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ingres` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `ingres` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `ingres` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `ingres` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 44 46 48 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-chg-only.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `iris` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 42 44 46 | 45 47 49 |
| xiaomi | `iris` | `thermal-mgame.conf` | `MGAME-SS-CPU1` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 42 44 46 | 45 47 49 |
| xiaomi | `iris` | `thermal-mgame.conf` | `MGAME-SS-CPU2` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 42 44 46 | 45 47 49 |
| xiaomi | `iris` | `thermal-mgame.conf` | `MGAME-SS-CPU3` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 42 44 46 | 45 47 49 |
| xiaomi | `iris` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 42 44 46 | 45 47 49 |
| xiaomi | `iris` | `thermal-mgame.conf` | `MGAME-SS-CPU5` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 42 44 46 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-nolimits.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 48 | 44 46 53 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `iris` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `jasmine_sprout` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL` | `quiet_therm` | 40 | 45 | 5 | 36 37 39 40 | 41 42 44 45 |
| xiaomi | `jasmine_sprout` | `thermal-engine-normal.conf` | `CPU2_HOTPLUG_MONITOR` | `quiet_therm` | 41 | 46 | 5 | 41 | 46 |
| xiaomi | `jasmine_sprout` | `thermal-engine-normal.conf` | `CPU3_HOTPLUG_MONITOR` | `tsens_tz_sensor5` | 60 | 65 | 5 | 60 | 65 |
| xiaomi | `jasmine_sprout` | `thermal-engine-normal.conf` | `CPU5_HOTPLUG_MONITOR` | `quiet_therm` | 40 | 45 | 5 | 40 | 45 |
| xiaomi | `jasmine_sprout` | `thermal-engine-normal.conf` | `CPU7_HOTPLUG_MONITOR` | `tsens_tz_sensor5` | 62 | 67 | 5 | 62 | 67 |
| xiaomi | `jasmine_sprout` | `thermal-engine-normal.conf` | `LCD_MANAGEMENT` | `xo_therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `jasmine_sprout` | `thermal-engine-video.conf` | `BATTERY_CHARGING_CTL` | `quiet_therm` | 40 | 45 | 5 | 36 37 39 40 | 41 42 44 45 |
| xiaomi | `jasmine_sprout` | `thermal-engine-video.conf` | `CPU2_HOTPLUG_MONITOR` | `quiet_therm` | 41 | 46 | 5 | 41 | 46 |
| xiaomi | `jasmine_sprout` | `thermal-engine-video.conf` | `CPU3_HOTPLUG_MONITOR` | `tsens_tz_sensor5` | 60 | 65 | 5 | 60 | 65 |
| xiaomi | `jasmine_sprout` | `thermal-engine-video.conf` | `CPU5_HOTPLUG_MONITOR` | `quiet_therm` | 40 | 45 | 5 | 40 | 45 |
| xiaomi | `jasmine_sprout` | `thermal-engine-video.conf` | `CPU7_HOTPLUG_MONITOR` | `tsens_tz_sensor5` | 62 | 67 | 5 | 62 | 67 |
| xiaomi | `jasmine_sprout` | `thermal-engine-video.conf` | `CPU_HOTPLUG_MONITOR` | `quiet_therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `jasmine_sprout` | `thermal-engine-video.conf` | `LCD_MANAGEMENT` | `xo_therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `joyeuse` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 42 | 47 | 5 | 36 37 38 39 41 42 | 41 42 43 44 46 47 |
| xiaomi | `joyeuse` | `thermal-engine-camera.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `joyeuse` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-usr` | 43 | 48 | 5 | 37 38 39 40 41 42 43 | 42 43 44 45 46 47 48 |
| xiaomi | `joyeuse` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `backlight_therm` | 47 | 52 | 5 | 40 44 47 | 45 49 52 |
| xiaomi | `lake` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `lake` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `lake` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `lake` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 38 40 42 43 44 45 | 42 44 46 47 48 49 |
| xiaomi | `lake` | `thermal-cgame.conf` | `CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 38 40 42 43 44 45 | 42 44 46 47 48 49 |
| xiaomi | `lake` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `lake` | `thermal-hp-game.conf` | `HP-GAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `lake` | `thermal-hp-game.conf` | `HP-GAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 38 40 42 44 45 46 | 42 44 46 48 49 50 |
| xiaomi | `lake` | `thermal-hp-game.conf` | `HP-GAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 38 40 42 44 45 46 | 42 44 46 48 49 50 |
| xiaomi | `lake` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `lake` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 41 43 45 46 48 | 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 41 43 45 47 48 | 44 46 48 50 51 |
| xiaomi | `lake` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-livestream.conf` | `LIVESTREAM-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 37 39 41 43 44 45 46 | 41 43 45 47 48 49 50 |
| xiaomi | `lake` | `thermal-livestream.conf` | `LIVESTREAM-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 37 39 41 43 44 45 46 | 41 43 45 47 48 49 50 |
| xiaomi | `lake` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `lake` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `lake` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `lake` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `lake` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 46 48 | 40 42 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `lake` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 43 | 47 |
| xiaomi | `lake` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 39 41 43 46 48 | 38 42 44 46 49 51 |
| xiaomi | `lake` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 39 41 43 46 48 | 38 42 44 46 49 51 |
| xiaomi | `lake` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `lake` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `lake` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 37 39 41 43 44 45 46 | 41 43 45 47 48 49 50 |
| xiaomi | `lake` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 37 39 41 43 44 45 46 | 41 43 45 47 48 49 50 |
| xiaomi | `lake` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 36 41 43 45 46 48 | 39 44 46 48 49 51 |
| xiaomi | `lake` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 36 41 43 45 46 48 | 39 44 46 48 49 51 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `lancelot` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `lancelot` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `lancelot` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `lancelot` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `lancelot` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lancelot` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 48 50 | 51 53 |
| xiaomi | `lancelot` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `lancelot` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 39 41 48 | 43 45 52 |
| xiaomi | `lancelot` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 51 | 38 53 |
| xiaomi | `lancelot` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `lancelot` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 38 40 42 44 46 50 51 | 38 40 42 44 46 48 52 53 |
| xiaomi | `lancelot` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `lancelot` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `land` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `case_therm` | 48 | 53 | 5 | 41 42 45 48 | 46 47 50 53 |
| xiaomi | `land` | `thermal-engine.conf` | `CAMERA_CAMCORDER_MONITOR` | `case_therm` | 430 | 430 | 0 | 40 430 | 45 430 |
| xiaomi | `land` | `thermal-engine.conf` | `CPU0_HOTPLUG_MONITOR` | `case_therm` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `land` | `thermal-engine.conf` | `CPU1_HOTPLUG_MONITOR` | `case_therm` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `lavender` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL` | `quiet_therm` | 43 | 48 | 5 | 37 38 41 42 43 | 42 43 46 47 48 |
| xiaomi | `lavender` | `thermal-engine-normal.conf` | `CPU2_HOTPLUG_MONITOR` | `msm_therm` | 43 | 48 | 5 | 43 | 48 |
| xiaomi | `lavender` | `thermal-engine-normal.conf` | `CPU3_HOTPLUG_MONITOR` | `msm_therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `lavender` | `thermal-engine-normal.conf` | `CPU5_HOTPLUG_MONITOR` | `msm_therm` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `lavender` | `thermal-engine-normal.conf` | `CPU7_HOTPLUG_MONITOR` | `msm_therm` | 49 | 54 | 5 | 49 | 54 |
| xiaomi | `lavender` | `thermal-engine-normal.conf` | `LCD_MANAGEMENT` | `backlight_therm` | 45 | 50 | 5 | 43 45 | 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `light` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `light` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 42 44 47 49 51 | 44 46 49 51 53 |
| xiaomi | `light` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU1` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU2` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU3` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU5` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `light` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `light` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `light` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 42 44 47 49 51 | 44 46 49 51 53 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 48 | 44 46 53 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU1` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU2` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU3` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU5` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `light` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU1` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU2` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU3` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU5` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU1` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU2` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU3` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU5` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `light` | `thermal-youtube.conf` | `YTB-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 45 | 42 44 46 50 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 44 46 48 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-chg-only.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-nolimits.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 39 41 48 | 44 46 53 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 43 45 47 | 45 47 49 |
| xiaomi | `lime` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `liuqin` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `liuqin` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `liuqin` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `liuqin` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `liuqin` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 38 39 41 43 45 47 48 | 28 41 42 44 46 48 50 51 |
| xiaomi | `liuqin` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 28 39 41 43 45 47 48 | 31 42 44 46 48 50 51 |
| xiaomi | `liuqin` | `thermal-cgame.conf` | `CGMAE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `liuqin` | `thermal-cgame.conf` | `CGMAE-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 15 46 | 17 48 |
| xiaomi | `liuqin` | `thermal-cgame.conf` | `CGMAE-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `liuqin` | `thermal-cgame.conf` | `CGMAE-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `liuqin` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `liuqin` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 46 47 | 29 39 41 43 45 47 49 50 51 |
| xiaomi | `liuqin` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 47 48 | 42 44 46 47 48 49 50 51 |
| xiaomi | `liuqin` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 48 | 42 44 46 47 48 49 51 |
| xiaomi | `liuqin` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 47 48 | 42 44 46 47 48 49 50 51 |
| xiaomi | `liuqin` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 41 43 44 46 47 | 43 45 47 48 50 51 |
| xiaomi | `liuqin` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `liuqin` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `liuqin` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `liuqin` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `liuqin` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `liuqin` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `liuqin` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `liuqin` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 43 44 45 46 47 48 | 41 43 46 47 48 49 50 51 |
| xiaomi | `liuqin` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 43 44 45 46 47 48 | 41 43 46 47 48 49 50 51 |
| xiaomi | `liuqin` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `liuqin` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `liuqin` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `liuqin` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 47 48 | 42 44 46 47 48 49 50 51 |
| xiaomi | `liuqin` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 41 43 44 46 47 | 43 45 47 48 50 51 |
| xiaomi | `liuqin` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `liuqin` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38 39 41 43 45 47 48 | 38 41 42 44 46 48 50 51 |
| xiaomi | `liuqin` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 39 41 43 45 47 | 42 43 45 47 49 51 |
| xiaomi | `liuqin` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `liuqin` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `liuqin` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `lmi` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 45.5 | 51 | 5.5 | 43.5 44.5 45.5 | 49 50 51 |
| xiaomi | `lmi` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 43 44 45 | 49 50 51 |
| xiaomi | `marble` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `marble` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 33 35 37 39 41 43 45 47 48 | 18 36 38 40 42 44 46 48 50 51 |
| xiaomi | `marble` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 33 35 37 39 41 43 45 47 48 | 18 36 38 40 42 44 46 48 50 51 |
| xiaomi | `marble` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `marble` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 33 35 37 39 41 43 45 47 48 | 18 36 38 40 42 44 46 48 50 51 |
| xiaomi | `marble` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 33 35 37 39 41 43 45 47 48 | 18 36 38 40 42 44 46 48 50 51 |
| xiaomi | `marble` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 37 39 41 43 44 45 47 48 50 | 26 38 40 42 44 45 46 48 49 51 |
| xiaomi | `marble` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 15 25 37 39 41 43 44 45 47 48 50 | 16 26 38 40 42 44 45 46 48 49 51 |
| xiaomi | `marble` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 15 43 46 | 17 45 48 |
| xiaomi | `marble` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `marble` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `marble` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 44 | 50 | 6 | 10 30 35 37 39 41 42 43 44 | 16 36 41 43 45 47 48 49 50 |
| xiaomi | `marble` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 44 45 46 47 48 | 28 40 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 25 37 39 41 43 44 45 46 47 48 | 18 28 40 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `marble` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 15 25 35 37 39 41 43 44 45 46 47 48 50 | 16 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `marble` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `marble` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `marble` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 43 44 46 | 48 49 51 |
| xiaomi | `marble` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 43 44 45 46 | 48 49 50 51 |
| xiaomi | `marble` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `marble` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 44 45 46 47 48 | 28 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 44 45 46 47 48 | 28 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `marble` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42 | 48 | 6 | 25 42 | 31 48 |
| xiaomi | `marble` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 25 30 32 35 39 40 42.5 | 21 31 36 38 41 45 46 48.5 |
| xiaomi | `marble` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 25 30 32 35 39 40 42.5 | 21 31 36 38 41 45 46 48.5 |
| xiaomi | `marble` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `marble` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `marble` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 43 44 46 | 48 49 51 |
| xiaomi | `marble` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 43 44 45 46 | 48 49 50 51 |
| xiaomi | `marble` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `marble` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 15 33 35 37 39 41 43 44 45 46 47 | 19 37 39 41 43 45 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 15 33 35 37 39 41 43 44 45 47 | 19 37 39 41 43 45 47 48 49 51 |
| xiaomi | `marble` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 44 45 46 47 48 | 28 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-normal.conf` | `NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 25 39 41 43 44 45 46 47 48 | 18 28 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 15 37 39 41 43 44 45 47 48 50 | 16 38 40 42 44 45 46 48 49 51 |
| xiaomi | `marble` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 15 37 39 41 43 44 45 47 48 50 | 16 38 40 42 44 45 46 48 49 51 |
| xiaomi | `marble` | `thermal-per-cgame.conf` | `PER-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-per-cgame.conf` | `PER-CGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 48 | 18 51 |
| xiaomi | `marble` | `thermal-per-cgame.conf` | `PER-CGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 48 | 18 51 |
| xiaomi | `marble` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 47 48 | 18 40 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 47 48 | 18 40 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `marble` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 15 33 35 37 39 41 43 44 45 46 47 | 19 37 39 41 43 45 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 15 33 35 37 39 41 43 44 45 47 | 19 37 39 41 43 45 47 48 49 51 |
| xiaomi | `marble` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 40 41 43 44 45 46 48 | 18 42 43 44 46 47 48 49 51 |
| xiaomi | `marble` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 40 41 43 44 45 46 47 48 | 18 42 43 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 15 35 37 39 41 43 44 45 46 47 48 50 | 16 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `marble` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 35 37 39 41 43 44 45 46 47 48 | 18 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `marble` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `marble` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 25 36 45 | 21 31 42 51 |
| xiaomi | `marble` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 25 42 45 | 21 31 48 51 |
| xiaomi | `marble` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `marble` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `marble` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `marble` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `marble` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `marble` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `marble` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 15 25 35 37 39 41 43 44 45 46 47 48 50 | 16 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `marble` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `marble` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 30 35 37 39 41 43 45 47 48 | 18 33 38 40 42 44 46 48 50 51 |
| xiaomi | `marble` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 15 30 35 37 39 41 43 45 47 | 19 34 39 41 43 45 47 49 51 |
| xiaomi | `marble` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `marble` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `marble` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `markw` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `case_therm` | 45 | 50 | 5 | 42 45 | 47 50 |
| xiaomi | `markw` | `thermal-engine.conf` | `CPU0_HOTPLUG_MONITOR` | `case_therm` | 40 | 45 | 5 | 40 | 45 |
| xiaomi | `markw` | `thermal-engine.conf` | `CPU1_HOTPLUG_MONITOR` | `case_therm` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `mayfly` | `thermal-abnormal.conf` | `ABNORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-abnormal.conf` | `ABNORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 41 42 45 46 47 48 | 28 42 43 44 45 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-abnormal.conf` | `ABNORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 41 42 45 47 48 | 28 42 43 44 45 48 50 51 |
| xiaomi | `mayfly` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 44 46 48 | 47 49 51 |
| xiaomi | `mayfly` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mayfly` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mayfly` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 44 | 50 | 6 | 10 30 35 37 39 41 42 43 44 | 16 36 41 43 45 47 48 49 50 |
| xiaomi | `mayfly` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 44 45 47 48 | 28 40 42 44 47 48 50 51 |
| xiaomi | `mayfly` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 44 45 47 48 | 28 40 42 44 47 48 50 51 |
| xiaomi | `mayfly` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 44 45 46 47 50 | 26 36 38 40 42 45 46 47 48 51 |
| xiaomi | `mayfly` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 25 35 37 39 41 44 45 47 | 29 39 41 43 45 48 49 51 |
| xiaomi | `mayfly` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 42 | 48 | 6 | 35 37 39 42 | 41 43 45 48 |
| xiaomi | `mayfly` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42 | 48 | 6 | 25 42 | 31 48 |
| xiaomi | `mayfly` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `mayfly` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `mayfly` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mayfly` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `mayfly` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mayfly` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mayfly` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 35 37 39 41 43 44 45 46 47 | 39 41 43 45 47 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 43 44 45 46 47 48 | 28 42 44 46 47 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-normal.conf` | `NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 41 44 45 46 47 48 | 28 42 44 47 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `mayfly` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `mayfly` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `mayfly` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 37 39 40 41 43 44 45 46 47 | 41 43 44 45 47 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 37 39 40 41 43 44 45 46 | 42 44 45 46 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `mayfly` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 41 42 45 46 47 48 | 42 43 44 45 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 41 42 45 47 48 | 42 43 44 45 48 50 51 |
| xiaomi | `mayfly` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `mayfly` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `mayfly` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `mayfly` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `mayfly` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `mayfly` | `thermal-sptm.conf` | `SPTM-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 45 | 51 |
| xiaomi | `mayfly` | `thermal-sptm.conf` | `SPTM-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 46 47 48 | 48 49 50 51 |
| xiaomi | `mayfly` | `thermal-sptm.conf` | `SPTM-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `mayfly` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mayfly` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mayfly` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mayfly` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 44 45 46 47 50 | 26 36 38 40 42 45 46 47 48 51 |
| xiaomi | `mayfly` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 25 35 37 39 41 44 45 47 | 29 39 41 43 45 48 49 51 |
| xiaomi | `mayfly` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mayfly` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 30 35 37 39 41 43 45 47 48 | 28 33 38 40 42 44 46 48 50 51 |
| xiaomi | `mayfly` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 47 | 51 | 4 | 25 30 35 37 39 41 43 45 47 | 29 34 39 41 43 45 47 49 51 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `merlin` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `merlin` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `merlin` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `merlin` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `merlin` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `merlin` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-normal.conf` | `SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-normal.conf` | `SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-normal.conf` | `SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `merlin` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 48 50 | 51 53 |
| xiaomi | `merlin` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 48 50 | 51 53 |
| xiaomi | `merlin` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `merlin` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 39 41 48 | 43 45 52 |
| xiaomi | `merlin` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 51 | 38 53 |
| xiaomi | `merlin` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 51 | 38 53 |
| xiaomi | `merlin` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `merlin` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 53 | 55 | 2 | 51 53 | 53 55 |
| xiaomi | `merlin` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `merlin` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-4k.conf` | `4K-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 43 46 48 | 18 28 46 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 47 48 | 18 40 42 50 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 37 39 47 48 | 18 28 40 42 50 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-8k.conf` | `8K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-8k.conf` | `8K-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-8k.conf` | `8K-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 43 46 48 | 18 28 46 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 47 | 51 | 4 | 15 35 38 40 43 45 47 | 19 39 42 44 47 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 37 39 41 43 45 48 | 18 28 40 42 44 46 48 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 43 46 48 | 18 28 46 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 47 | 51 | 4 | 15 35 38 40 43 46 47 | 19 39 42 44 47 50 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 35 39 41 43 45 48 | 18 28 38 42 44 46 48 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 32 45 | 19 29 36 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 41 43 46 | 19 29 39 41 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 35 37 39 45 46 48 | 18 28 38 40 42 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 45 50 | 46 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-charge.conf` | `CHARGE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-charge.conf` | `CHARGE-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-charge.conf` | `CHARGE-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-charge.conf` | `CHARGE-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 40 46 | 19 29 44 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-charge.conf` | `CHARGE-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 30 35 39 41 43 46 | 29 34 39 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-charge.conf` | `CHARGE-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 32 39 40 43 45 46 48 | 28 35 42 43 46 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 40 45 46 | 19 29 44 49 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 39 41 43 46 | 19 29 39 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 39 40 43 45 46 48 | 18 28 42 43 46 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 32 45 46 | 19 29 36 49 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 41 43 46 | 19 29 39 41 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 35 37 39 45 46 48 | 18 28 38 40 42 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-danmu.conf` | `DANMU-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-danmu.conf` | `DANMU-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-danmu.conf` | `DANMU-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-danmu.conf` | `DANMU-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 32 45 | 19 29 36 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-danmu.conf` | `DANMU-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 39 41 43 46 | 19 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-danmu.conf` | `DANMU-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 40 43 45 46 | 19 29 44 47 49 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 41 43 46 | 19 29 39 41 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 37 | 41 | 4 | 15 25 35 37 | 19 29 39 41 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 44 | 48 | 4 | 15 38 43 44 | 19 42 47 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 36 42 42.7 43.4 44.1 44.8 46 | 19 29 40 46 46.7 47.4 48.1 48.8 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 36 41 42.5 43.5 44.8 46 48 | 18 28 39 44 45.5 46.5 47.8 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 40 45 46 | 19 29 44 49 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 47 | 51 | 4 | 15 25 35 39 41 43 46 47 | 19 29 39 43 45 47 50 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 39 40 45 46 48 | 18 28 42 43 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 42 | 46 | 4 | 15 25 35 42 | 19 29 39 46 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 42 | 46 | 4 | 15 25 35 37 39 41 42 | 19 29 39 41 43 45 46 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 39 | 43 | 4 | 15 25 35 37 39 | 19 29 39 41 43 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 48 | 18 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 43 | 47 | 4 | 15 25 35 37 39 43 | 19 29 39 41 43 47 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 35 37 39 45 | 19 29 39 41 43 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 40 48 | 18 28 43 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 35 39 41 43 48 | 18 28 38 42 44 46 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 39 40 43 45 46 48 | 18 28 42 43 46 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 32 46 | 19 29 36 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 41 43 46 | 19 29 39 41 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 35 37 39 45 46 48 | 18 28 38 40 42 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 40 48 | 18 43 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 35 39 41 43 48 | 18 38 42 44 46 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 39 40 43 45 46 48 | 18 28 42 43 46 48 49 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 32 | 36 | 4 | 15 25 32 | 19 29 36 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 41 43 46 | 19 29 39 41 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 45 46 | 19 29 39 41 43 49 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 40 45 | 19 44 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 35 45 | 19 29 39 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 35 45 | 19 29 39 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 32 | 36 | 4 | 15 25 32 | 19 29 36 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 41 43 46 | 19 29 39 41 43 45 47 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 25 35 37 39 45 46 | 19 29 39 41 43 49 50 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 48 | 18 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 35 39 41 45 | 19 29 39 43 45 49 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 35 | 39 | 4 | 15 25 35 | 19 29 39 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-xingtie.conf` | `XINGTIE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-xingtie.conf` | `XINGTIE-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_64only_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k-gl.conf` | `4K-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k-gl.conf` | `4K-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 41 45 48 | 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k-gl.conf` | `4K-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43.5 45 48 | 38 40 42 44 46.5 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k-india.conf` | `IN-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k-india.conf` | `IN-4K-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k-india.conf` | `IN-4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42.5 45 48 | 38 40 42 44 45.5 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42.5 45 48 | 38 40 42 44 45.5 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera-gl.conf` | `CAMERA-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera-gl.conf` | `CAMERA-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 44 48 | 43 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera-gl.conf` | `CAMERA-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 45 48 | 38 40 42 43 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera-india.conf` | `IN-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera-india.conf` | `IN-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 44 48 | 43 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera-india.conf` | `IN-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 45 48 | 38 40 42 43 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 44 48 | 43 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 45 48 | 38 40 42 43 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-gl.conf` | `CCLASSVIDEO-GL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-gl.conf` | `CCLASSVIDEO-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-gl.conf` | `CCLASSVIDEO-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-gl.conf` | `CCLASSVIDEO-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 32 35 37 41 43 44 | 36 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-india.conf` | `IN-CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-india.conf` | `IN-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-india.conf` | `IN-CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo-india.conf` | `IN-CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 32 35 37 41 43 44 | 36 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 32 35 37 41 43 44 | 36 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-gl.conf` | `CGAME-GL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 40 | 44 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-gl.conf` | `CGAME-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-gl.conf` | `CGAME-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 36 42 46 48 | 39 45 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-gl.conf` | `CGAME-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 39 42 44 46 | 40 43 46 48 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-india.conf` | `IN-CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 40 | 44 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-india.conf` | `IN-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-india.conf` | `IN-CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 36 42 46 48 | 39 45 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame-india.conf` | `IN-CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 39 42 44 46 | 40 43 46 48 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 40 | 44 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 36 42 46 48 | 39 45 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 39 42 44 46 | 40 43 46 48 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-chg-only-gl.conf` | `CHG-GL-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-chg-only-gl.conf` | `CHG-GL-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-chg-only-india.conf` | `IN-CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-chg-only-india.conf` | `IN-CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-class0-gl.conf` | `CLASS0-GL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-class0-gl.conf` | `CLASS0-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-class0-india.conf` | `IN-CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-class0-india.conf` | `IN-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-gl.conf` | `DEMO-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-gl.conf` | `DEMO-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-gl.conf` | `DEMO-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-4k.conf` | `IN-DEMO-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-4k.conf` | `IN-DEMO-4K-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 44 48 | 43 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-4k.conf` | `IN-DEMO-4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 45 48 | 38 40 42 43 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-camera.conf` | `IN-DEMO-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-camera.conf` | `IN-DEMO-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 44 48 | 43 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-camera.conf` | `IN-DEMO-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 45 48 | 38 40 42 43 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cclassvideo.conf` | `IN-DEMO-CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cclassvideo.conf` | `IN-DEMO-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cclassvideo.conf` | `IN-DEMO-CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cclassvideo.conf` | `IN-DEMO-CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 32 35 37 41 43 44 | 36 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cgame.conf` | `IN-DEMO-CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 40 | 44 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cgame.conf` | `IN-DEMO-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cgame.conf` | `IN-DEMO-CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 38 41 43 46 | 40 42 45 47 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-cgame.conf` | `IN-DEMO-CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 38 41 43 46 | 40 42 45 47 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-chg-only.conf` | `IN-DEMO-CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-chg-only.conf` | `IN-DEMO-CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-class0.conf` | `IN-DEMO-CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-class0.conf` | `IN-DEMO-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-demo.conf` | `IN-DEMO-DEMO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-demo.conf` | `IN-DEMO-DEMO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-demo.conf` | `IN-DEMO-DEMO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-dolbyvision.conf` | `IN-DEMO-DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-dolbyvision.conf` | `IN-DEMO-DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-dolbyvision.conf` | `IN-DEMO-DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-dolbyvision.conf` | `IN-DEMO-DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-highfps.conf` | `IN-DEMO-HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-highfps.conf` | `IN-DEMO-HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-highfps.conf` | `IN-DEMO-HIGHFPS-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-highfps.conf` | `IN-DEMO-HIGHFPS-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 35 37 41 43 44 | 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-mgame.conf` | `IN-DEMO-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-mgame.conf` | `IN-DEMO-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-mgame.conf` | `IN-DEMO-HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-mgame.conf` | `IN-DEMO-HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-normal.conf` | `IN-DEMO-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-normal.conf` | `IN-DEMO-HP-NORMAL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-normal.conf` | `IN-DEMO-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-normal.conf` | `IN-DEMO-HP-NORMAL-SS-CPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-hp-normal.conf` | `IN-DEMO-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-huanji.conf` | `IN-DEMO-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-huanji.conf` | `IN-DEMO-HUANJI-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-huanji.conf` | `IN-DEMO-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-huanji.conf` | `IN-DEMO-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-huanji.conf` | `IN-DEMO-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-mgame.conf` | `IN-DEMO-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-mgame.conf` | `IN-DEMO-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-mgame.conf` | `IN-DEMO-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-mgame.conf` | `IN-DEMO-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-navigation.conf` | `IN-DEMO-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-navigation.conf` | `IN-DEMO-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-navigation.conf` | `IN-DEMO-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 32 35 37 39 41 43 45 | 36 39 41 43 45 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-normal.conf` | `IN-DEMO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-normal.conf` | `IN-DEMO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-normal.conf` | `IN-DEMO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-class0.conf` | `IN-DEMO-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-class0.conf` | `IN-DEMO-PER-CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-class0.conf` | `IN-DEMO-PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-class0.conf` | `IN-DEMO-PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-class0.conf` | `IN-DEMO-PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 28 30 41 42 45 48 | 28 31 33 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-normal.conf` | `IN-DEMO-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-normal.conf` | `IN-DEMO-PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-normal.conf` | `IN-DEMO-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-video.conf` | `IN-DEMO-PER-VIDEO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-video.conf` | `IN-DEMO-PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-video.conf` | `IN-DEMO-PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 43 45 | 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-per-video.conf` | `IN-DEMO-PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 37 41 43 44 45 | 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-phone.conf` | `IN-DEMO-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-phone.conf` | `IN-DEMO-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-phone.conf` | `IN-DEMO-PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-tgame.conf` | `IN-DEMO-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-tgame.conf` | `IN-DEMO-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-tgame.conf` | `IN-DEMO-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-tgame.conf` | `IN-DEMO-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-toutiao.conf` | `IN-DEMO-TOUTIAO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-toutiao.conf` | `IN-DEMO-TOUTIAO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-toutiao.conf` | `IN-DEMO-TOUTIAO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-video.conf` | `IN-DEMO-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-video.conf` | `IN-DEMO-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 43 48 | 38 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-video.conf` | `IN-DEMO-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-videochat.conf` | `IN-DEMO-VIDEOCHAT-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-videochat.conf` | `IN-DEMO-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-videochat.conf` | `IN-DEMO-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 43 47 | 40 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-ind-videochat.conf` | `IN-DEMO-VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 36 38 41 43 47 | 29 39 40 42 45 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-india.conf` | `IN-DEMO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-india.conf` | `IN-DEMO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo-india.conf` | `IN-DEMO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo.conf` | `DEMO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo.conf` | `DEMO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-demo.conf` | `DEMO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-gl.conf` | `DOLBYVISION-GL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-gl.conf` | `DOLBYVISION-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-gl.conf` | `DOLBYVISION-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-gl.conf` | `DOLBYVISION-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-india.conf` | `IN-DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-india.conf` | `IN-DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-india.conf` | `IN-DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision-india.conf` | `IN-DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-gl.conf` | `HIGHFPS-GL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-gl.conf` | `HIGHFPS-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-gl.conf` | `HIGHFPS-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-gl.conf` | `HIGHFPS-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 35 37 41 43 44 | 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-india.conf` | `IN-HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-india.conf` | `IN-HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-india.conf` | `IN-HIGHFPS-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps-india.conf` | `IN-HIGHFPS-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 35 37 41 43 44 | 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 43 45 | 39 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 35 37 41 43 44 | 39 41 45 47 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-gl.conf` | `HP-GL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-gl.conf` | `HP-GL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-gl.conf` | `HP-GL-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-gl.conf` | `HP-GL-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-india.conf` | `IN-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-india.conf` | `IN-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-india.conf` | `IN-HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame-india.conf` | `IN-HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 30 38 39 40 42 46 | 34 42 43 44 46 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-gl.conf` | `HP-GL-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-gl.conf` | `HP-GL-NORMAL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-gl.conf` | `HP-GL-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-gl.conf` | `HP-GL-NORMAL-SS-CPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-gl.conf` | `HP-GL-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-india.conf` | `IN-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-india.conf` | `IN-HP-NORMAL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-india.conf` | `IN-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-india.conf` | `IN-HP-NORMAL-SS-CPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal-india.conf` | `IN-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37.5 39 43 45 47 | 40 41.5 43 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-gl.conf` | `HUANJI-GL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-gl.conf` | `HUANJI-GL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-gl.conf` | `HUANJI-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-gl.conf` | `HUANJI-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-gl.conf` | `HUANJI-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-india.conf` | `IN-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-india.conf` | `IN-HUANJI-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-india.conf` | `IN-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-india.conf` | `IN-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji-india.conf` | `IN-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 34 36 37 42 47 | 36 38 40 41 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-gl.conf` | `MGAME-GL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-gl.conf` | `MGAME-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-gl.conf` | `MGAME-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-gl.conf` | `MGAME-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-india.conf` | `IN-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-india.conf` | `IN-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-india.conf` | `IN-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame-india.conf` | `IN-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 39 40 43 44 46.5 | 43 44 47 48 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation-gl.conf` | `NAVIGATION-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation-gl.conf` | `NAVIGATION-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation-gl.conf` | `NAVIGATION-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 32 35 37 39 41 43 45 | 36 39 41 43 45 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation-india.conf` | `IN-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation-india.conf` | `IN-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation-india.conf` | `IN-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 32 35 37 39 41 43 45 | 36 39 41 43 45 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 32 35 37 39 41 43 45 | 36 39 41 43 45 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal-gl.conf` | `MONITOR-GL-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal-gl.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal-gl.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal-india.conf` | `IN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal-india.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal-india.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 48 | 41 43 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 44 47 | 42 44 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-gl.conf` | `PER-GL-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-gl.conf` | `PER-GL-CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-gl.conf` | `PER-GL-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-gl.conf` | `PER-GL-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-gl.conf` | `PER-GL-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 28 30 41 42 45 48 | 28 31 33 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-india.conf` | `IN-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-india.conf` | `IN-PER-CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-india.conf` | `IN-PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-india.conf` | `IN-PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0-india.conf` | `IN-PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 28 30 41 42 45 48 | 28 31 33 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 28 30 41 42 45 48 | 28 31 33 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal-gl.conf` | `PER-GL-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal-gl.conf` | `PER-GL-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal-gl.conf` | `PER-GL-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal-india.conf` | `IN-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal-india.conf` | `IN-PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal-india.conf` | `IN-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 44 47.5 | 42.5 44.5 47.5 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-gl.conf` | `PER-GL-VIDEO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-gl.conf` | `PER-GL-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-gl.conf` | `PER-GL-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 43 45 | 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-gl.conf` | `PER-GL-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 37 41 43 44 45 | 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-india.conf` | `IN-PER-VIDEO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-india.conf` | `IN-PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-india.conf` | `IN-PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 43 45 | 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video-india.conf` | `IN-PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 37 41 43 44 45 | 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 43 45 | 47 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 37 41 43 44 45 | 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone-gl.conf` | `PHONE-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone-gl.conf` | `PHONE-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone-gl.conf` | `PHONE-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone-india.conf` | `IN-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone-india.conf` | `IN-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone-india.conf` | `IN-PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 30 44 | 29 34 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-gl.conf` | `TGAME-GL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-gl.conf` | `TGAME-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-gl.conf` | `TGAME-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-gl.conf` | `TGAME-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-india.conf` | `IN-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-india.conf` | `IN-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-india.conf` | `IN-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame-india.conf` | `IN-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 40 41 43 45 46.5 | 44 45 47 49 50.5 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao-gl.conf` | `TOUTIAO-GL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao-gl.conf` | `TOUTIAO-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao-gl.conf` | `TOUTIAO-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao-india.conf` | `IN-TOUTIAO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao-india.conf` | `IN-TOUTIAO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao-india.conf` | `IN-TOUTIAO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao.conf` | `TOUTIAO-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao.conf` | `TOUTIAO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-toutiao.conf` | `TOUTIAO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36 37 41 42 45 48 | 28 38 39 40 44 45 48 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-video-gl.conf` | `VIDEO-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-video-gl.conf` | `VIDEO-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 43 48 | 38 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-video-gl.conf` | `VIDEO-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-video-india.conf` | `IN-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-video-india.conf` | `IN-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 43 48 | 38 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-video-india.conf` | `IN-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 43 48 | 38 46 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 37 41 43 44 45 | 39 41 45 47 48 49 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-gl.conf` | `VIDEOCHAT-GL-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-gl.conf` | `VIDEOCHAT-GL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-gl.conf` | `VIDEOCHAT-GL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 43 47 | 40 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-gl.conf` | `VIDEOCHAT-GL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 36 38 41 43 47 | 29 39 40 42 45 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-india.conf` | `IN-VIDEOCHAT-MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-india.conf` | `IN-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-india.conf` | `IN-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 43 47 | 40 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat-india.conf` | `IN-VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 36 38 41 43 47 | 29 39 40 42 45 47 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 43 45 | 46 48 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 43 45 47 | 40 47 49 51 |
| xiaomi | `mgvi_64_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 36 38 41 43 47 | 29 39 40 42 45 47 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-4k.conf` | `4K-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 43 46 48 | 18 28 46 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 47 48 | 18 40 42 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 37 39 47 48 | 18 28 40 42 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-8k.conf` | `8K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-8k.conf` | `8K-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-8k.conf` | `8K-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 43 46 48 | 18 28 46 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 47 | 51 | 4 | 15 35 38 40 43 45 47 | 19 39 42 44 47 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 37 39 41 43 45 48 | 18 28 40 42 44 46 48 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 43 46 48 | 18 28 46 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 47 | 51 | 4 | 15 35 38 40 43 46 47 | 19 39 42 44 47 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 25 35 39 41 43 45 48 | 18 28 38 42 44 46 48 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 36 38 40 42 43 46 | 19 40 42 44 46 47 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 36 38 40 42 46 | 19 40 42 44 46 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 45 50 | 46 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 38 39 40 44 45 46 47 48 | 18 41 42 43 47 48 49 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 40 43 44 45 46 48 | 18 40 42 43 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 39 41 43 44 45 46 47 48 | 18 42 44 46 47 48 49 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 48 | 18 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-danmu.conf` | `DANMU-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-danmu.conf` | `DANMU-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-danmu.conf` | `DANMU-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-danmu.conf` | `DANMU-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-danmu.conf` | `DANMU-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 48 | 18 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-danmu.conf` | `DANMU-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 35 37 39 41 43 44 45 46 48 | 18 38 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 48 | 18 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 35 37 39 41 43 44 45 46 48 | 18 38 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 38 39 40 44 45 46 47 48 | 18 41 42 43 47 48 49 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 40 43 44 45 46 48 | 18 40 42 43 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 42 | 46 | 4 | 15 25 35 42 | 19 29 39 46 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 42 | 46 | 4 | 15 25 35 37 39 41 42 | 19 29 39 41 43 45 46 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 39 | 43 | 4 | 15 25 35 37 39 | 19 29 39 41 43 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 25 46 | 29 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 47 | 51 | 4 | 15 37 39 41 43 45 46 47 | 19 41 43 45 47 49 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 37 39 41 43 45 46 | 19 41 43 45 47 49 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 38 39 40 44 45 46 47 48 | 18 41 42 43 47 48 49 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 40 43 44 45 46 48 | 18 40 42 43 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 39 41 43 44 45 46 47 48 | 18 42 44 46 47 48 49 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 48 | 18 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-normal.conf` | `PER-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-normal.conf` | `PER-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-normal.conf` | `PER-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-normal.conf` | `PER-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-normal.conf` | `PER-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 38 39 40 44 45 46 47 48 | 18 41 42 43 47 48 49 50 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-normal.conf` | `PER-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 40 43 44 45 46 48 | 18 40 42 43 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 48 | 18 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 35 37 39 41 43 44 45 46 48 | 18 38 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 40 45 | 19 44 49 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 35 45 | 19 29 39 49 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 45 | 49 | 4 | 15 25 35 45 | 19 29 39 49 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 47 | 16 26 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 37 39 41 43 44 45 46 48 | 18 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 35 37 39 41 43 44 45 46 48 | 18 38 40 42 44 46 47 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR-FORMULA` | 47 | 48 | 1 | 15 25 40 45 47 | 16 26 41 46 48 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 15 35 38 39 41 43 45 46 48 | 18 38 41 42 44 46 48 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 47 | 51 | 4 | 15 35 39 41 45 47 | 19 39 43 45 49 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-xingtie.conf` | `XINGTIE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-xingtie.conf` | `XINGTIE-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-CCC` | `VIRTUAL-SENSOR-FORMULA` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU0` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mgvi_t_64_64only_isp_wifi_armv82` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR-FORMULA` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `mihal` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-4k.conf` | `4K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `mihal` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 44 45 46 47 | 41 43 45 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 44 45 46 47 | 41 43 45 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 36 37 39 41 42 43 44 45 46 47 48 | 39 40 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-global-4k.conf` | `GLOBAL-4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-4k.conf` | `GLOBAL-4K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-4k.conf` | `GLOBAL-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-global-4k.conf` | `GLOBAL-4K-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-global-4k.conf` | `GLOBAL-4K-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `mihal` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 36 37 39 41 42 43 44 45 46 47 48 | 39 40 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 42 43 44 45 | 46 47 48 49 |
| xiaomi | `mihal` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 42 42.8 43.6 44.4 45 | 46 46.8 47.6 48.4 49 |
| xiaomi | `mihal` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 42 42.8 43.6 44.4 45 | 46 46.8 47.6 48.4 49 |
| xiaomi | `mihal` | `thermal-global-navigation.conf` | `GLOBAL-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-navigation.conf` | `GLOBAL-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-navigation.conf` | `GLOBAL-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-navigation.conf` | `GLOBAL-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-global-navigation.conf` | `GLOBAL-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-global-nolimits.conf` | `GLOBAL-NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-global-normal.conf` | `GLOBAL-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-normal.conf` | `GLOBAL-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-normal.conf` | `GLOBAL-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-normal.conf` | `GLOBAL-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 40 41 42 43 44 45 46 47 48 | 39 41 43 44 45 46 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-global-normal.conf` | `GLOBAL-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 41 42 43 44 45 46 47 48 | 38 40 42 43 44 45 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-global-per-camera.conf` | `GLOBAL-PER-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-per-camera.conf` | `GLOBAL-PER-CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-per-camera.conf` | `GLOBAL-PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-global-per-camera.conf` | `GLOBAL-PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-global-per-class0.conf` | `GLOBAL-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-per-class0.conf` | `GLOBAL-PER-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-per-class0.conf` | `GLOBAL-PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-per-class0.conf` | `GLOBAL-PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-global-per-class0.conf` | `GLOBAL-PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-global-per-navigation.conf` | `GLOBAL-PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-per-navigation.conf` | `GLOBAL-PER-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-per-navigation.conf` | `GLOBAL-PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-per-navigation.conf` | `GLOBAL-PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-global-per-navigation.conf` | `GLOBAL-PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 15 35 37 39 41 43 44 45 | 19 39 41 43 45 47 48 49 |
| xiaomi | `mihal` | `thermal-global-per-normal.conf` | `GLOBAL-PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-per-normal.conf` | `GLOBAL-PER-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-per-normal.conf` | `GLOBAL-PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-per-normal.conf` | `GLOBAL-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 40 41 42 43 44 45 46 47 48 | 39 41 43 44 45 46 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-global-per-video.conf` | `GLOBAL-PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-per-video.conf` | `GLOBAL-PER-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-per-video.conf` | `GLOBAL-PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-per-video.conf` | `GLOBAL-PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-global-per-video.conf` | `GLOBAL-PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-global-phone.conf` | `GLOBAL-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-phone.conf` | `GLOBAL-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-phone.conf` | `GLOBAL-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-phone.conf` | `GLOBAL-PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-global-phone.conf` | `GLOBAL-PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 46 48 | 48 50 52 |
| xiaomi | `mihal` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `mihal` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 44 45 45.7 46.5 47.2 48 | 47 48 48.7 49.5 50.2 51 |
| xiaomi | `mihal` | `thermal-global-video.conf` | `GLOBAL-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-video.conf` | `GLOBAL-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-global-video.conf` | `GLOBAL-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-global-video.conf` | `GLOBAL-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-global-video.conf` | `GLOBAL-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-global-videochat.conf` | `GLOBAL-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-global-videochat.conf` | `GLOBAL-VIDEOCHAT-MONITOR-CCC` | `VIRTUAL-SENSOR1` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 43 44 46 | 47 48 50 |
| xiaomi | `mihal` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 42 43.6 44.2 44.8 46 | 46 47.6 48.2 48.8 50 |
| xiaomi | `mihal` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 42 43.6 44.2 44.8 46 | 46 47.6 48.2 48.8 50 |
| xiaomi | `mihal` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-huanji.conf` | `HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-india-4k.conf` | `INDIA-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-india-4k.conf` | `INDIA-4K-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-india-4k.conf` | `INDIA-4K-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `mihal` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 37 39 41 43 45 46 | 41 43 45 47 49 50 |
| xiaomi | `mihal` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `mihal` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 36 37 39 41 42 43 44 45 46 47 48 | 39 40 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-india-huanji.conf` | `INDIA-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 42 43 44 45 | 46 47 48 49 |
| xiaomi | `mihal` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 42 42.8 43.6 44.4 45 | 46 46.8 47.6 48.4 49 |
| xiaomi | `mihal` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 42 42.8 43.6 44.4 45 | 46 46.8 47.6 48.4 49 |
| xiaomi | `mihal` | `thermal-india-navigation.conf` | `INDIA-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-navigation.conf` | `INDIA-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-india-navigation.conf` | `INDIA-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-india-nolimits.conf` | `INDIA-NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-india-normal.conf` | `INDIA-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-normal.conf` | `INDIA-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-india-normal.conf` | `INDIA-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-india-per-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `mihal` | `thermal-india-per-camera.conf` | `INDIA-PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-india-per-camera.conf` | `INDIA-PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 37 39 41 43 45 46 | 41 43 45 47 49 50 |
| xiaomi | `mihal` | `thermal-india-per-class0.conf` | `INDIA-PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-per-class0.conf` | `INDIA-PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-india-per-class0.conf` | `INDIA-PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-india-per-navigation.conf` | `INDIA-PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-per-navigation.conf` | `INDIA-PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-india-per-navigation.conf` | `INDIA-PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 15 35 37 39 41 43 44 45 | 19 39 41 43 45 47 48 49 |
| xiaomi | `mihal` | `thermal-india-per-normal.conf` | `INDIA-PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-per-normal.conf` | `INDIA-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-india-per-normal.conf` | `INDIA-PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-india-per-video.conf` | `INDIA-PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-per-video.conf` | `INDIA-PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-india-per-video.conf` | `INDIA-PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 46 48 | 48 50 52 |
| xiaomi | `mihal` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `mihal` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 44 45 45.7 46.5 47.2 48 | 47 48 48.7 49.5 50.2 51 |
| xiaomi | `mihal` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-4k.conf` | `4K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-l16u-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `mihal` | `thermal-l16u-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-l16u-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 36 37 39 41 42 43 44 45 46 47 48 | 39 40 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-l16u-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-huanji.conf` | `HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-l16u-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-l16u-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-l16u-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-l16u-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 43 44 46 | 47 48 50 |
| xiaomi | `mihal` | `thermal-l16u-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 42 43.6 44.2 44.8 46 | 46 47.6 48.2 48.8 50 |
| xiaomi | `mihal` | `thermal-l16u-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 42 43.6 44.2 44.8 46 | 46 47.6 48.2 48.8 50 |
| xiaomi | `mihal` | `thermal-l16u-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-navigation.conf` | `NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-l16u-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-l16u-nolimits.conf` | `NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-l16u-normal.conf` | `NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-normal.conf` | `NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-normal.conf` | `NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-l16u-normal.conf` | `NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-per-camera.conf` | `PER-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-camera.conf` | `PER-CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-camera.conf` | `PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-l16u-per-camera.conf` | `PER-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mihal` | `thermal-l16u-per-camera.conf` | `PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-per-camera.conf` | `PER-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `mihal` | `thermal-l16u-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-class0.conf` | `PER-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-l16u-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-per-huanji.conf` | `PER-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-huanji.conf` | `PER-HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-huanji.conf` | `PER-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-l16u-per-huanji.conf` | `PER-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-l16u-per-huanji.conf` | `PER-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-l16u-per-huanji.conf` | `PER-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-l16u-per-navigation.conf` | `PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-navigation.conf` | `PER-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-navigation.conf` | `PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-l16u-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-l16u-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-normal.conf` | `PER-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-normal.conf` | `PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-l16u-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-video.conf` | `PER-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-l16u-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-l16u-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-l16u-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-tgame.conf` | `TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 46 48 | 48 50 52 |
| xiaomi | `mihal` | `thermal-l16u-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `mihal` | `thermal-l16u-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 44 45 45.7 46.5 47.2 48 | 47 48 48.7 49.5 50.2 51 |
| xiaomi | `mihal` | `thermal-l16u-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-l16u-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-l16u-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-l16u-videochat.conf` | `VIDEOCHAT-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-l16u-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-l16u-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-l16u-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 15 35 37 39 41 43 44 45 | 19 39 41 43 45 47 48 49 |
| xiaomi | `mihal` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 43 44 46 | 47 48 50 |
| xiaomi | `mihal` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 42 43.6 44.2 44.8 46 | 46 47.6 48.2 48.8 50 |
| xiaomi | `mihal` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 42 43.6 44.2 44.8 46 | 46 47.6 48.2 48.8 50 |
| xiaomi | `mihal` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 25 48 | 29 52 |
| xiaomi | `mihal` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-nolimits.conf` | `NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-normal.conf` | `NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-normal.conf` | `NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-normal.conf` | `NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-normal.conf` | `NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `mihal` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-per-huanji.conf` | `PER-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-per-huanji.conf` | `PER-HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-per-huanji.conf` | `PER-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `mihal` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 33 35 37 38 39 40 41 42 | 19 37 39 41 42 43 44 45 46 |
| xiaomi | `mihal` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 25 48 | 29 52 |
| xiaomi | `mihal` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 25 48 | 29 52 |
| xiaomi | `mihal` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 45 | 29 49 |
| xiaomi | `mihal` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-tgame.conf` | `TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 46 48 | 48 50 52 |
| xiaomi | `mihal` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `mihal` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 44 45 45.7 46.5 47.2 48 | 47 48 48.7 49.5 50.2 51 |
| xiaomi | `mihal` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 35 | 39 | 4 | 35 | 39 |
| xiaomi | `mihal` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 37 39 41 43 44 45 46 47 48 | 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mihal` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 44 45 46 47 48 | 38 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mihal` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mihal` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `mihal` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `mihal` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 35 37 39 41 43 44 45 46 | 19 39 41 43 45 47 48 49 50 |
| xiaomi | `mihal` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 15 35 37 39 41 43 44 45 | 19 39 41 43 45 47 48 49 |
| xiaomi | `miproduct` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 42 44 45 46 47 | 46 48 49 50 51 |
| xiaomi | `miproduct` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 42 44 45 46 47 | 46 48 49 50 51 |
| xiaomi | `miproduct` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 41 43 45 46 47 48 | 44 45 47 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 45 46 47 48 | 44 46 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 41 42 44 46 47 | 42 44 45 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-cgame.conf` | `CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 46 47 48 | 44 46 48 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 47 48 | 44 46 48 49 51 52 |
| xiaomi | `miproduct` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `miproduct` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `miproduct` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 41 42 44 46 47 | 42 44 45 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `miproduct` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 45 47 | 42 44 46 48 49 51 |
| xiaomi | `miproduct` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 45 47 | 42 44 46 48 49 51 |
| xiaomi | `miproduct` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `miproduct` | `thermal-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `miproduct` | `thermal-in-arvr.conf` | `INDIA-ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 42 44 45 46 47 | 46 48 49 50 51 |
| xiaomi | `miproduct` | `thermal-in-arvr.conf` | `INDIA-ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 42 44 45 46 47 | 46 48 49 50 51 |
| xiaomi | `miproduct` | `thermal-in-camera.conf` | `INDIA-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 41 43 45 46 47 48 | 44 45 47 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-in-camera.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 45 46 47 48 | 44 46 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-in-cgame.conf` | `INDIA-CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 41 42 44 46 47 | 42 44 45 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-in-cgame.conf` | `INDIA-CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-in-chg-only.conf` | `INDIA-CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 46 47 48 | 44 46 48 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-in-chg-only.conf` | `INDIA-CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 47 48 | 44 46 48 49 51 52 |
| xiaomi | `miproduct` | `thermal-in-class0.conf` | `INDIA-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-in-class0.conf` | `INDIA-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `miproduct` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `miproduct` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 41 42 44 46 47 | 42 44 45 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `miproduct` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 45 47 | 42 44 46 48 49 51 |
| xiaomi | `miproduct` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 45 47 | 42 44 46 48 49 51 |
| xiaomi | `miproduct` | `thermal-in-huanji.conf` | `INDIA-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `miproduct` | `thermal-in-huanji.conf` | `INDIA-HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 43 45 46 48 | 41 43 45 47 49 50 52 |
| xiaomi | `miproduct` | `thermal-in-mgame.conf` | `INDIA-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 46.5 | 48 |
| xiaomi | `miproduct` | `thermal-in-mgame.conf` | `INDIA-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 46.5 | 48 |
| xiaomi | `miproduct` | `thermal-in-mgame.conf` | `INDIA-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 38 40 41 42 44 46 | 42 44 45 46 48 50 |
| xiaomi | `miproduct` | `thermal-in-mgame.conf` | `INDIA-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 40 42 44 46 | 44 46 48 50 |
| xiaomi | `miproduct` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 39 41 43 45 | 43 45 47 49 |
| xiaomi | `miproduct` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 39 41 43 45 | 43 45 47 49 |
| xiaomi | `miproduct` | `thermal-in-normal.conf` | `INDIA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 46 47 48 | 44 46 48 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-in-normal.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 47 48 | 44 46 48 49 51 52 |
| xiaomi | `miproduct` | `thermal-in-phone.conf` | `INDIA-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `miproduct` | `thermal-in-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 43 | 47 |
| xiaomi | `miproduct` | `thermal-in-phone.conf` | `INDIA-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 46 48 | 39 43 45 47 50 52 |
| xiaomi | `miproduct` | `thermal-in-phone.conf` | `INDIA-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 46 48 | 39 43 45 47 50 52 |
| xiaomi | `miproduct` | `thermal-in-tgame.conf` | `INDIA-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 46.5 | 48 |
| xiaomi | `miproduct` | `thermal-in-tgame.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 46.5 | 48 |
| xiaomi | `miproduct` | `thermal-in-tgame.conf` | `INDIA-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 38 40 41 42 44 46 | 42 44 45 46 48 50 |
| xiaomi | `miproduct` | `thermal-in-tgame.conf` | `INDIA-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 40 42 44 46 | 44 46 48 50 |
| xiaomi | `miproduct` | `thermal-in-video.conf` | `INDIA-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-in-video.conf` | `INDIA-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 41 43 45 46 47 48 | 45 47 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 41 43 45 46 47 48 | 45 47 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-livestream.conf` | `LIVESTREAM-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `miproduct` | `thermal-livestream.conf` | `LIVESTREAM-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47.5 | 48 | 0.5 | 46.5 47.5 | 47 48 |
| xiaomi | `miproduct` | `thermal-livestream.conf` | `LIVESTREAM-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 45 47 | 42 44 46 48 49 51 |
| xiaomi | `miproduct` | `thermal-livestream.conf` | `LIVESTREAM-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 45 47 | 42 44 46 48 49 51 |
| xiaomi | `miproduct` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 41 42 44 46 47 | 42 44 45 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 39 41 43 45 | 43 45 47 49 |
| xiaomi | `miproduct` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 39 41 43 45 | 43 45 47 49 |
| xiaomi | `miproduct` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 46 47 48 | 44 46 48 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 40 42 44 45 47 48 | 44 46 48 49 51 52 |
| xiaomi | `miproduct` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `miproduct` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 43 | 47 |
| xiaomi | `miproduct` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 46 48 | 39 43 45 47 50 52 |
| xiaomi | `miproduct` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 46 48 | 39 43 45 47 50 52 |
| xiaomi | `miproduct` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 41 42 44 46 47 | 42 44 45 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `miproduct` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 38 40 42 44 46 48 | 42 44 46 48 50 52 |
| xiaomi | `miproduct` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 41 43 45 46 47 48 | 45 47 49 50 51 52 |
| xiaomi | `miproduct` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 41 43 45 46 47 48 | 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-4k.conf` | `4K-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-4k.conf` | `4K-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-4k.conf` | `4K-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mivendor` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-camera.conf` | `CAMERA-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-camera.conf` | `CAMERA-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-camera.conf` | `CAMERA-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 15 43 46 | 17 45 48 |
| xiaomi | `mivendor` | `thermal-cgame.conf` | `CGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-cgame.conf` | `CGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-cgame.conf` | `CGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-charge.conf` | `CHARGE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-charge.conf` | `CHARGE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-charge.conf` | `CHARGE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-charge.conf` | `CHARGE-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-chg-only.conf` | `CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-chg-only.conf` | `CHG-ONLY-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-class0.conf` | `CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-class0.conf` | `CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 47 48 50 | 27 34 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-class0.conf` | `CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-danmu.conf` | `DANMU-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-danmu.conf` | `DANMU-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-danmu.conf` | `DANMU-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-danmu.conf` | `DANMU-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-danmu.conf` | `DANMU-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-danmu.conf` | `DANMU-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-4k.conf` | `GLOBAL-4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-gl-4k.conf` | `GLOBAL-4K-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-gl-4k.conf` | `GLOBAL-4K-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-gl-4k.conf` | `GLOBAL-4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-gl-4k.conf` | `GLOBAL-4K-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-arvr.conf` | `GLOBAL-ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-arvr.conf` | `GLOBAL-ARVR-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mivendor` | `thermal-gl-camera.conf` | `GLOBAL-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-gl-camera.conf` | `GLOBAL-CAMERA-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-gl-camera.conf` | `GLOBAL-CAMERA-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-gl-camera.conf` | `GLOBAL-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-gl-camera.conf` | `GLOBAL-CAMERA-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-cclassvideo.conf` | `GLOBAL-CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-cclassvideo.conf` | `GLOBAL-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-cclassvideo.conf` | `GLOBAL-CCLASSVIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-cclassvideo.conf` | `GLOBAL-CCLASSVIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-cclassvideo.conf` | `GLOBAL-CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-cclassvideo.conf` | `GLOBAL-CCLASSVIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-cgame.conf` | `GLOBAL-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-cgame.conf` | `GLOBAL-CGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 15 43 46 | 17 45 48 |
| xiaomi | `mivendor` | `thermal-gl-cgame.conf` | `GLOBAL-CGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-gl-cgame.conf` | `GLOBAL-CGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-gl-cgame.conf` | `GLOBAL-CGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-gl-cgame.conf` | `GLOBAL-CGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-chg-only.conf` | `GLOBAL-CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-chg-only.conf` | `GLOBAL-CHG-ONLY-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-chg-only.conf` | `GLOBAL-CHG-ONLY-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-chg-only.conf` | `GLOBAL-CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-chg-only.conf` | `GLOBAL-CHG-ONLY-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-class0.conf` | `GLOBAL-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-class0.conf` | `GLOBAL-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-class0.conf` | `GLOBAL-CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-class0.conf` | `GLOBAL-CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-class0.conf` | `GLOBAL-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 47 48 50 | 27 34 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-class0.conf` | `GLOBAL-CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-danmu.conf` | `GLOBAL-DANMU-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-danmu.conf` | `GLOBAL-DANMU-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-danmu.conf` | `GLOBAL-DANMU-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-gl-danmu.conf` | `GLOBAL-DANMU-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-gl-danmu.conf` | `GLOBAL-DANMU-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-danmu.conf` | `GLOBAL-DANMU-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-highfps.conf` | `GLOBAL-HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-highfps.conf` | `GLOBAL-HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-highfps.conf` | `GLOBAL-HIGHFPS-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-gl-highfps.conf` | `GLOBAL-HIGHFPS-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-gl-highfps.conf` | `GLOBAL-HIGHFPS-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 35 37 39 41 43 44 45 46 47 48 | 19 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-highfps.conf` | `GLOBAL-HIGHFPS-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-hp-mgame.conf` | `GLOBAL-HP-MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 40 45 46 | 42 47 48 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-hp-normal.conf` | `GLOBAL-HP-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-huanji.conf` | `GLOBAL-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-huanji.conf` | `GLOBAL-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-huanji.conf` | `GLOBAL-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `mivendor` | `thermal-gl-huanji.conf` | `GLOBAL-HUANJI-SS-CPU2` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-gl-huanji.conf` | `GLOBAL-HUANJI-SS-CPU5` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-gl-huanji.conf` | `GLOBAL-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-gl-huanji.conf` | `GLOBAL-HUANJI-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-mgame.conf` | `GLOBAL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-mgame.conf` | `GLOBAL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-mgame.conf` | `GLOBAL-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-gl-mgame.conf` | `GLOBAL-MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-mgame.conf` | `GLOBAL-MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-mgame.conf` | `GLOBAL-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-mgame.conf` | `GLOBAL-MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-navigation.conf` | `GLOBAL-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-navigation.conf` | `GLOBAL-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-navigation.conf` | `GLOBAL-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 39 41 43 45 | 42 44 46 48 |
| xiaomi | `mivendor` | `thermal-gl-navigation.conf` | `GLOBAL-NAVIGATION-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-gl-navigation.conf` | `GLOBAL-NAVIGATION-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-gl-navigation.conf` | `GLOBAL-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-gl-navigation.conf` | `GLOBAL-NAVIGATION-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-nolimits.conf` | `GLOBAL-NOLIMITS-SS-CPU2` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-gl-nolimits.conf` | `GLOBAL-NOLIMITS-SS-CPU5` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-gl-nolimits.conf` | `GLOBAL-NOLIMITS-SS-CPU7` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-gl-normal.conf` | `GLOBAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-normal.conf` | `GLOBAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-normal.conf` | `GLOBAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-normal.conf` | `GLOBAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-normal.conf` | `GLOBAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-normal.conf` | `GLOBAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-per-class0.conf` | `GLOBAL-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-per-class0.conf` | `GLOBAL-PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-per-class0.conf` | `GLOBAL-PER-CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-class0.conf` | `GLOBAL-PER-CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-class0.conf` | `GLOBAL-PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-class0.conf` | `GLOBAL-PER-CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-per-normal.conf` | `GLOBAL-PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-per-normal.conf` | `GLOBAL-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `mivendor` | `thermal-gl-per-normal.conf` | `GLOBAL-PER-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-normal.conf` | `GLOBAL-PER-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-normal.conf` | `GLOBAL-PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-normal.conf` | `GLOBAL-PER-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-per-video.conf` | `GLOBAL-PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-per-video.conf` | `GLOBAL-PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-per-video.conf` | `GLOBAL-PER-VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-video.conf` | `GLOBAL-PER-VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-video.conf` | `GLOBAL-PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-gl-per-video.conf` | `GLOBAL-PER-VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-phone.conf` | `GLOBAL-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-phone.conf` | `GLOBAL-PHONE-SS-CPU2` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-gl-phone.conf` | `GLOBAL-PHONE-SS-CPU5` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-gl-phone.conf` | `GLOBAL-PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-gl-phone.conf` | `GLOBAL-PHONE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-recharge.conf` | `GLOBAL-RECHARGE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-recharge.conf` | `GLOBAL-RECHARGE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-recharge.conf` | `GLOBAL-RECHARGE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 15 50 | 17 52 |
| xiaomi | `mivendor` | `thermal-gl-recharge.conf` | `GLOBAL-RECHARGE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 15 50 | 17 52 |
| xiaomi | `mivendor` | `thermal-gl-recharge.conf` | `GLOBAL-RECHARGE-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 48 | 19 52 |
| xiaomi | `mivendor` | `thermal-gl-recharge.conf` | `GLOBAL-RECHARGE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-tgame.conf` | `GLOBAL-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-tgame.conf` | `GLOBAL-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-tgame.conf` | `GLOBAL-TGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-tgame.conf` | `GLOBAL-TGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-tgame.conf` | `GLOBAL-TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-gl-tgame.conf` | `GLOBAL-TGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-video.conf` | `GLOBAL-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-video.conf` | `GLOBAL-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-video.conf` | `GLOBAL-VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-video.conf` | `GLOBAL-VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-video.conf` | `GLOBAL-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-gl-video.conf` | `GLOBAL-VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-videochat.conf` | `GLOBAL-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-videochat.conf` | `GLOBAL-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-gl-videochat.conf` | `GLOBAL-VIDEOCHAT-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-gl-videochat.conf` | `GLOBAL-VIDEOCHAT-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-gl-videochat.conf` | `GLOBAL-VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 35 37 39 41 43 45 48 | 29 39 41 43 45 47 49 52 |
| xiaomi | `mivendor` | `thermal-gl-videochat.conf` | `GLOBAL-VIDEOCHAT-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-xingtie.conf` | `GLOBAL-XINGTIE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-xingtie.conf` | `GLOBAL-XINGTIE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-gl-xingtie.conf` | `GLOBAL-XINGTIE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-gl-xingtie.conf` | `GLOBAL-XINGTIE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-gl-xingtie.conf` | `GLOBAL-XINGTIE-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-gl-xingtie.conf` | `GLOBAL-XINGTIE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-gl-yuanshen.conf` | `GLOBAL-YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-gl-yuanshen.conf` | `GLOBAL-YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mivendor` | `thermal-gl-yuanshen.conf` | `GLOBAL-YUANSHEN-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-gl-yuanshen.conf` | `GLOBAL-YUANSHEN-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-gl-yuanshen.conf` | `GLOBAL-YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-gl-yuanshen.conf` | `GLOBAL-YUANSHEN-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-highfps.conf` | `HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-highfps.conf` | `HIGHFPS-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 35 37 39 41 43 44 45 46 47 48 | 19 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-highfps.conf` | `HIGHFPS-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 40 45 46 | 42 47 48 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `mivendor` | `thermal-huanji.conf` | `HUANJI-SS-CPU2` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-huanji.conf` | `HUANJI-SS-CPU5` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-huanji.conf` | `HUANJI-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-4k.conf` | `INDIA-4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-in-4k.conf` | `INDIA-4K-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-4k.conf` | `INDIA-4K-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-4k.conf` | `INDIA-4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-4k.conf` | `INDIA-4K-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-arvr.conf` | `INDIA-ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-arvr.conf` | `INDIA-ARVR-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mivendor` | `thermal-in-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-in-camera.conf` | `INDIA-CAMERA-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-camera.conf` | `INDIA-CAMERA-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-camera.conf` | `INDIA-CAMERA-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-cclassvideo.conf` | `INDIA-CCLASSVIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-cgame.conf` | `INDIA-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-cgame.conf` | `INDIA-CGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 15 43 46 | 17 45 48 |
| xiaomi | `mivendor` | `thermal-in-cgame.conf` | `INDIA-CGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-in-cgame.conf` | `INDIA-CGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-in-cgame.conf` | `INDIA-CGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-in-cgame.conf` | `INDIA-CGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-chg-only.conf` | `INDIA-CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-chg-only.conf` | `INDIA-CHG-ONLY-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-chg-only.conf` | `INDIA-CHG-ONLY-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-chg-only.conf` | `INDIA-CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-chg-only.conf` | `INDIA-CHG-ONLY-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-class0.conf` | `INDIA-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-class0.conf` | `INDIA-CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-class0.conf` | `INDIA-CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-class0.conf` | `INDIA-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 47 48 50 | 27 34 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-class0.conf` | `INDIA-CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-danmu.conf` | `INDIA-DANMU-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-danmu.conf` | `INDIA-DANMU-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-danmu.conf` | `INDIA-DANMU-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-danmu.conf` | `INDIA-DANMU-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-danmu.conf` | `INDIA-DANMU-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-danmu.conf` | `INDIA-DANMU-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-4k.conf` | `INDIA-DEMO-4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-in-demo-4k.conf` | `INDIA-DEMO-4K-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-demo-4k.conf` | `INDIA-DEMO-4K-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-demo-4k.conf` | `INDIA-DEMO-4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-demo-4k.conf` | `INDIA-DEMO-4K-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-arvr.conf` | `INDIA-DEMO-ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-arvr.conf` | `INDIA-DEMO-ARVR-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `mivendor` | `thermal-in-demo-camera.conf` | `INDIA-DEMO-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 41 45 | 21 47 51 |
| xiaomi | `mivendor` | `thermal-in-demo-camera.conf` | `INDIA-DEMO-CAMERA-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-demo-camera.conf` | `INDIA-DEMO-CAMERA-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-demo-camera.conf` | `INDIA-DEMO-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 37 39 41 43 48 | 19 41 43 45 47 52 |
| xiaomi | `mivendor` | `thermal-in-demo-camera.conf` | `INDIA-DEMO-CAMERA-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-cclassvideo.conf` | `INDIA-DEMO-CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-cclassvideo.conf` | `INDIA-DEMO-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-cclassvideo.conf` | `INDIA-DEMO-CCLASSVIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-cclassvideo.conf` | `INDIA-DEMO-CCLASSVIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-cclassvideo.conf` | `INDIA-DEMO-CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 37 39 41 43 44 45 47 48 50 | 27 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-cclassvideo.conf` | `INDIA-DEMO-CCLASSVIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-cgame.conf` | `INDIA-DEMO-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-cgame.conf` | `INDIA-DEMO-CGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 15 43 46 | 17 45 48 |
| xiaomi | `mivendor` | `thermal-in-demo-cgame.conf` | `INDIA-DEMO-CGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-in-demo-cgame.conf` | `INDIA-DEMO-CGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-in-demo-cgame.conf` | `INDIA-DEMO-CGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 15 43 46 | 21 49 52 |
| xiaomi | `mivendor` | `thermal-in-demo-cgame.conf` | `INDIA-DEMO-CGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-chg-only.conf` | `INDIA-DEMO-CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-chg-only.conf` | `INDIA-DEMO-CHG-ONLY-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-chg-only.conf` | `INDIA-DEMO-CHG-ONLY-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-chg-only.conf` | `INDIA-DEMO-CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 39 41 43 44 45 46 47 48 | 29 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-chg-only.conf` | `INDIA-DEMO-CHG-ONLY-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-class0.conf` | `INDIA-DEMO-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-class0.conf` | `INDIA-DEMO-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-class0.conf` | `INDIA-DEMO-CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-class0.conf` | `INDIA-DEMO-CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-class0.conf` | `INDIA-DEMO-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 47 48 50 | 27 34 39 41 43 45 46 47 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-class0.conf` | `INDIA-DEMO-CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-danmu.conf` | `INDIA-DEMO-DANMU-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-danmu.conf` | `INDIA-DEMO-DANMU-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-danmu.conf` | `INDIA-DEMO-DANMU-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-danmu.conf` | `INDIA-DEMO-DANMU-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 32 35 37 39 41 43 45 46 | 31 38 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-danmu.conf` | `INDIA-DEMO-DANMU-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-danmu.conf` | `INDIA-DEMO-DANMU-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-highfps.conf` | `INDIA-DEMO-HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-highfps.conf` | `INDIA-DEMO-HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-highfps.conf` | `INDIA-DEMO-HIGHFPS-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-highfps.conf` | `INDIA-DEMO-HIGHFPS-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-highfps.conf` | `INDIA-DEMO-HIGHFPS-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 35 37 39 41 43 44 45 46 47 48 | 19 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-highfps.conf` | `INDIA-DEMO-HIGHFPS-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-mgame.conf` | `INDIA-DEMO-HP-MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 40 45 46 | 42 47 48 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-hp-normal.conf` | `INDIA-DEMO-HP-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-huanji.conf` | `INDIA-DEMO-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-huanji.conf` | `INDIA-DEMO-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-huanji.conf` | `INDIA-DEMO-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `mivendor` | `thermal-in-demo-huanji.conf` | `INDIA-DEMO-HUANJI-SS-CPU2` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-in-demo-huanji.conf` | `INDIA-DEMO-HUANJI-SS-CPU5` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-in-demo-huanji.conf` | `INDIA-DEMO-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-in-demo-huanji.conf` | `INDIA-DEMO-HUANJI-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-mgame.conf` | `INDIA-DEMO-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-mgame.conf` | `INDIA-DEMO-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-mgame.conf` | `INDIA-DEMO-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-in-demo-mgame.conf` | `INDIA-DEMO-MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-mgame.conf` | `INDIA-DEMO-MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-mgame.conf` | `INDIA-DEMO-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-mgame.conf` | `INDIA-DEMO-MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-navigation.conf` | `INDIA-DEMO-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-navigation.conf` | `INDIA-DEMO-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-navigation.conf` | `INDIA-DEMO-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 39 41 43 45 | 42 44 46 48 |
| xiaomi | `mivendor` | `thermal-in-demo-navigation.conf` | `INDIA-DEMO-NAVIGATION-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-demo-navigation.conf` | `INDIA-DEMO-NAVIGATION-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-demo-navigation.conf` | `INDIA-DEMO-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-demo-navigation.conf` | `INDIA-DEMO-NAVIGATION-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-nolimits.conf` | `INDIA-DEMO-NOLIMITS-SS-CPU2` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-nolimits.conf` | `INDIA-DEMO-NOLIMITS-SS-CPU5` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-nolimits.conf` | `INDIA-DEMO-NOLIMITS-SS-CPU7` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-normal.conf` | `INDIA-DEMO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-normal.conf` | `INDIA-DEMO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-normal.conf` | `INDIA-DEMO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-normal.conf` | `INDIA-DEMO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-normal.conf` | `INDIA-DEMO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-normal.conf` | `INDIA-DEMO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-per-class0.conf` | `INDIA-DEMO-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-per-class0.conf` | `INDIA-DEMO-PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-per-class0.conf` | `INDIA-DEMO-PER-CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-class0.conf` | `INDIA-DEMO-PER-CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-class0.conf` | `INDIA-DEMO-PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-class0.conf` | `INDIA-DEMO-PER-CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-per-normal.conf` | `INDIA-DEMO-PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-per-normal.conf` | `INDIA-DEMO-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `mivendor` | `thermal-in-demo-per-normal.conf` | `INDIA-DEMO-PER-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-normal.conf` | `INDIA-DEMO-PER-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-normal.conf` | `INDIA-DEMO-PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-normal.conf` | `INDIA-DEMO-PER-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-per-video.conf` | `INDIA-DEMO-PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-per-video.conf` | `INDIA-DEMO-PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-per-video.conf` | `INDIA-DEMO-PER-VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-video.conf` | `INDIA-DEMO-PER-VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-video.conf` | `INDIA-DEMO-PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-demo-per-video.conf` | `INDIA-DEMO-PER-VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-phone.conf` | `INDIA-DEMO-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-phone.conf` | `INDIA-DEMO-PHONE-SS-CPU2` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-in-demo-phone.conf` | `INDIA-DEMO-PHONE-SS-CPU5` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-in-demo-phone.conf` | `INDIA-DEMO-PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-in-demo-phone.conf` | `INDIA-DEMO-PHONE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-tgame.conf` | `INDIA-DEMO-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-tgame.conf` | `INDIA-DEMO-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-tgame.conf` | `INDIA-DEMO-TGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-tgame.conf` | `INDIA-DEMO-TGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-tgame.conf` | `INDIA-DEMO-TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-demo-tgame.conf` | `INDIA-DEMO-TGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-video.conf` | `INDIA-DEMO-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-video.conf` | `INDIA-DEMO-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-video.conf` | `INDIA-DEMO-VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-video.conf` | `INDIA-DEMO-VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-video.conf` | `INDIA-DEMO-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-demo-video.conf` | `INDIA-DEMO-VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-videochat.conf` | `INDIA-DEMO-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-videochat.conf` | `INDIA-DEMO-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-demo-videochat.conf` | `INDIA-DEMO-VIDEOCHAT-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-demo-videochat.conf` | `INDIA-DEMO-VIDEOCHAT-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-demo-videochat.conf` | `INDIA-DEMO-VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 35 37 39 41 43 45 48 | 29 39 41 43 45 47 49 52 |
| xiaomi | `mivendor` | `thermal-in-demo-videochat.conf` | `INDIA-DEMO-VIDEOCHAT-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-xingtie.conf` | `INDIA-DEMO-XINGTIE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-xingtie.conf` | `INDIA-DEMO-XINGTIE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-demo-xingtie.conf` | `INDIA-DEMO-XINGTIE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-xingtie.conf` | `INDIA-DEMO-XINGTIE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-xingtie.conf` | `INDIA-DEMO-XINGTIE-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-xingtie.conf` | `INDIA-DEMO-XINGTIE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-demo-yuanshen.conf` | `INDIA-DEMO-YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-demo-yuanshen.conf` | `INDIA-DEMO-YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mivendor` | `thermal-in-demo-yuanshen.conf` | `INDIA-DEMO-YUANSHEN-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-yuanshen.conf` | `INDIA-DEMO-YUANSHEN-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-yuanshen.conf` | `INDIA-DEMO-YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-in-demo-yuanshen.conf` | `INDIA-DEMO-YUANSHEN-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-highfps.conf` | `INDIA-HIGHFPS-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-highfps.conf` | `INDIA-HIGHFPS-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-highfps.conf` | `INDIA-HIGHFPS-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-highfps.conf` | `INDIA-HIGHFPS-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 35 37 39 41 43 45 46 | 31 41 43 45 47 49 51 52 |
| xiaomi | `mivendor` | `thermal-in-highfps.conf` | `INDIA-HIGHFPS-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 35 37 39 41 43 44 45 46 47 48 | 19 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-highfps.conf` | `INDIA-HIGHFPS-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-hp-mgame.conf` | `INDIA-HP-MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR0` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 40 45 46 | 42 47 48 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 25 37 39 41 43 44 45 46 | 31 43 45 47 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-hp-normal.conf` | `INDIA-HP-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-huanji.conf` | `INDIA-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-huanji.conf` | `INDIA-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-huanji.conf` | `INDIA-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `mivendor` | `thermal-in-huanji.conf` | `INDIA-HUANJI-SS-CPU2` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-in-huanji.conf` | `INDIA-HUANJI-SS-CPU5` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-in-huanji.conf` | `INDIA-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mivendor` | `thermal-in-huanji.conf` | `INDIA-HUANJI-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-mgame.conf` | `INDIA-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-mgame.conf` | `INDIA-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-mgame.conf` | `INDIA-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-in-mgame.conf` | `INDIA-MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-mgame.conf` | `INDIA-MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-mgame.conf` | `INDIA-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-mgame.conf` | `INDIA-MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 39 41 43 45 | 42 44 46 48 |
| xiaomi | `mivendor` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-navigation.conf` | `INDIA-NAVIGATION-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-nolimits.conf` | `INDIA-NOLIMITS-SS-CPU2` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-in-nolimits.conf` | `INDIA-NOLIMITS-SS-CPU5` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-in-nolimits.conf` | `INDIA-NOLIMITS-SS-CPU7` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-in-normal.conf` | `INDIA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-normal.conf` | `INDIA-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-normal.conf` | `INDIA-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-normal.conf` | `INDIA-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-per-class0.conf` | `INDIA-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-per-class0.conf` | `INDIA-PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-per-class0.conf` | `INDIA-PER-CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-class0.conf` | `INDIA-PER-CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-class0.conf` | `INDIA-PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-class0.conf` | `INDIA-PER-CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-per-normal.conf` | `INDIA-PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-per-normal.conf` | `INDIA-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `mivendor` | `thermal-in-per-normal.conf` | `INDIA-PER-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-normal.conf` | `INDIA-PER-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-normal.conf` | `INDIA-PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-normal.conf` | `INDIA-PER-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-per-video.conf` | `INDIA-PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-per-video.conf` | `INDIA-PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-per-video.conf` | `INDIA-PER-VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-video.conf` | `INDIA-PER-VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-video.conf` | `INDIA-PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-in-per-video.conf` | `INDIA-PER-VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-phone.conf` | `INDIA-PHONE-SS-CPU2` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-in-phone.conf` | `INDIA-PHONE-SS-CPU5` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-in-phone.conf` | `INDIA-PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-in-phone.conf` | `INDIA-PHONE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-recharge.conf` | `INDIA-RECHARGE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-recharge.conf` | `INDIA-RECHARGE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-recharge.conf` | `INDIA-RECHARGE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 15 50 | 17 52 |
| xiaomi | `mivendor` | `thermal-in-recharge.conf` | `INDIA-RECHARGE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 15 50 | 17 52 |
| xiaomi | `mivendor` | `thermal-in-recharge.conf` | `INDIA-RECHARGE-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 48 | 19 52 |
| xiaomi | `mivendor` | `thermal-in-recharge.conf` | `INDIA-RECHARGE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-tgame.conf` | `INDIA-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-tgame.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-tgame.conf` | `INDIA-TGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-tgame.conf` | `INDIA-TGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-tgame.conf` | `INDIA-TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-in-tgame.conf` | `INDIA-TGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-video.conf` | `INDIA-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-video.conf` | `INDIA-VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-video.conf` | `INDIA-VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-video.conf` | `INDIA-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-in-video.conf` | `INDIA-VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 35 37 39 41 43 45 48 | 29 39 41 43 45 47 49 52 |
| xiaomi | `mivendor` | `thermal-in-videochat.conf` | `INDIA-VIDEOCHAT-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-xingtie.conf` | `INDIA-XINGTIE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-xingtie.conf` | `INDIA-XINGTIE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-in-xingtie.conf` | `INDIA-XINGTIE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-in-xingtie.conf` | `INDIA-XINGTIE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-in-xingtie.conf` | `INDIA-XINGTIE-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-in-xingtie.conf` | `INDIA-XINGTIE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-in-yuanshen.conf` | `INDIA-YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-in-yuanshen.conf` | `INDIA-YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mivendor` | `thermal-in-yuanshen.conf` | `INDIA-YUANSHEN-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-in-yuanshen.conf` | `INDIA-YUANSHEN-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-in-yuanshen.conf` | `INDIA-YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-in-yuanshen.conf` | `INDIA-YUANSHEN-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mivendor` | `thermal-mgame.conf` | `MGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-mgame.conf` | `MGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 52 | 6 | 36 42.5 43.2 43.9 44.6 45.3 46 | 42 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-mgame.conf` | `MGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 39 41 43 45 | 42 44 46 48 |
| xiaomi | `mivendor` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-navigation.conf` | `NAVIGATION-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-nolimits.conf` | `NOLIMITS-SS-CPU2` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-nolimits.conf` | `NOLIMITS-SS-CPU5` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-nolimits.conf` | `NOLIMITS-SS-CPU7` | `VIRTUAL-SENSOR0` | 51 | 52 | 1 | 51 | 52 |
| xiaomi | `mivendor` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-normal.conf` | `SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-normal.conf` | `SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 25 32 37 39 41 43 44 45 46 47 48 49 50 | 27 34 39 41 43 45 46 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 37 39 41 43 44 45 46 47 48 | 29 36 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-normal.conf` | `SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-class0.conf` | `PER-CLASS0-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `mivendor` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 37 39 41 43 44 45 46 47 48 50 | 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-normal.conf` | `PER-NORMAL-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 35 37 39 41 43 44 45 46 47 48 50 | 37 39 41 43 45 46 47 48 49 50 52 |
| xiaomi | `mivendor` | `thermal-per-video.conf` | `PER-VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-phone.conf` | `PHONE-SS-CPU2` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-phone.conf` | `PHONE-SS-CPU5` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 15 36 41 | 21 42 47 |
| xiaomi | `mivendor` | `thermal-phone.conf` | `PHONE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-recharge.conf` | `RECHARGE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-recharge.conf` | `RECHARGE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-recharge.conf` | `RECHARGE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 15 50 | 17 52 |
| xiaomi | `mivendor` | `thermal-recharge.conf` | `RECHARGE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 15 50 | 17 52 |
| xiaomi | `mivendor` | `thermal-recharge.conf` | `RECHARGE-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 48 | 19 52 |
| xiaomi | `mivendor` | `thermal-recharge.conf` | `RECHARGE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-tgame.conf` | `TGAME-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-tgame.conf` | `TGAME-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 47.5 48.5 49.2 49.9 50.6 51.3 52 |
| xiaomi | `mivendor` | `thermal-tgame.conf` | `TGAME-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-video.conf` | `VIDEO-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-video.conf` | `VIDEO-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 32 35 37 39 41 43 44 45 46 47 48 | 29 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 15 32 35 37 39 41 43 44 45 46 47 48 | 19 36 39 41 43 45 47 48 49 50 51 52 |
| xiaomi | `mivendor` | `thermal-video.conf` | `VIDEO-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 40 45 | 21 46 51 |
| xiaomi | `mivendor` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU2` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU5` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mivendor` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 25 35 37 39 41 43 45 48 | 29 39 41 43 45 47 49 52 |
| xiaomi | `mivendor` | `thermal-videochat.conf` | `VIDEOCHAT-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-xingtie.conf` | `XINGTIE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-xingtie.conf` | `XINGTIE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mivendor` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU2` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU5` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-xingtie.conf` | `XINGTIE-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mivendor` | `thermal-xingtie.conf` | `XINGTIE-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mivendor` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mivendor` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mivendor` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU2` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU5` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `mivendor` | `thermal-yuanshen.conf` | `YUANSHEN-SS-LMH_CPU7` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `mojito` | `thermal-arvr.conf` | `SS-CPU0` | `sdm-therm` | 52 | 55 | 3 | 52 | 55 |
| xiaomi | `mojito` | `thermal-arvr.conf` | `SS-CPU0-1` | `sdm-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `mojito` | `thermal-arvr.conf` | `SS-CPU6` | `sdm-therm` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `mojito` | `thermal-arvr.conf` | `SS-CPU6-1` | `sdm-therm` | 53 | 54 | 1 | 53 | 54 |
| xiaomi | `mojito` | `thermal-camera.conf` | `MONITOR-CPU2` | `sdm-therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mojito` | `thermal-camera.conf` | `MONITOR-CPU3` | `sdm-therm` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `mojito` | `thermal-camera.conf` | `MONITOR-CPU5` | `sdm-therm` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `mojito` | `thermal-camera.conf` | `MONITOR-CPU7` | `sdm-therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mojito` | `thermal-camera.conf` | `MONITOR-CPU_HOTPLUG` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `mojito` | `thermal-camera.conf` | `SS-CPU0` | `sdm-therm` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `mojito` | `thermal-camera.conf` | `SS-CPU0-1` | `sdm-therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mojito` | `thermal-camera.conf` | `SS-CPU0-2` | `sdm-therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `mojito` | `thermal-camera.conf` | `SS-CPU6` | `sdm-therm` | 43 | 48 | 5 | 43 | 48 |
| xiaomi | `mojito` | `thermal-camera.conf` | `SS-CPU6-1` | `sdm-therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `mojito` | `thermal-camera.conf` | `SS-CPU6-2` | `sdm-therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `MONITOR-CPU2` | `sdm-therm` | 52 | 54 | 2 | 52 | 54 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `MONITOR-CPU3` | `sdm-therm` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `MONITOR-CPU5` | `sdm-therm` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `MONITOR-CPU7` | `sdm-therm` | 52 | 54 | 2 | 52 | 54 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `MONITOR-CPU_HOTPLUG` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `SS-CPU0` | `sdm-therm` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `SS-CPU0-1` | `sdm-therm` | 52 | 55 | 3 | 52 | 55 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `SS-CPU0-2` | `sdm-therm` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `SS-CPU6` | `sdm-therm` | 49 | 54 | 5 | 49 | 54 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `SS-CPU6-1` | `sdm-therm` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `mojito` | `thermal-camera2.conf` | `SS-CPU6-2` | `sdm-therm` | 52 | 54 | 2 | 52 | 54 |
| xiaomi | `mojito` | `thermal-mgame.conf` | `MGAME-MONITOR-CPU2` | `sdm-therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `mojito` | `thermal-mgame.conf` | `MGAME-MONITOR-CPU3` | `sdm-therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mojito` | `thermal-mgame.conf` | `MGAME-MONITOR-CPU5` | `sdm-therm` | 47.5 | 50 | 2.5 | 47.5 | 50 |
| xiaomi | `mojito` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `sdm-therm` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mojito` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `sdm-therm` | 45 | 50 | 5 | 15 45 | 20 50 |
| xiaomi | `mojito` | `thermal-normal.conf` | `SS-CPU0` | `sdm-therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `mojito` | `thermal-normal.conf` | `SS-CPU6` | `sdm-therm` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `mojito` | `thermal-phone.conf` | `SS-CPU0` | `sdm-therm` | 40 | 45 | 5 | 40 | 45 |
| xiaomi | `mojito` | `thermal-phone.conf` | `SS-CPU6` | `sdm-therm` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `MONITOR-CPU2` | `sdm-therm` | 49 | 54 | 5 | 49 | 54 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `MONITOR-CPU3` | `sdm-therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `MONITOR-CPU5` | `sdm-therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `SS-CPU0` | `sdm-therm` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `SS-CPU0-1` | `sdm-therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `SS-CPU0-2` | `sdm-therm` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `SS-CPU6` | `sdm-therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `SS-CPU6-1` | `sdm-therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `mojito` | `thermal-tgame.conf` | `SS-CPU6-2` | `sdm-therm` | 49 | 54 | 5 | 49 | 54 |
| xiaomi | `mona` | `thermal-chg-only.conf` | `CHG-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 39 41 42 43.5 49 | 41 43 44 45.5 51 |
| xiaomi | `mona` | `thermal-chg-only.conf` | `CHG-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 39 41 42 43.5 49 | 41 43 44 45.5 51 |
| xiaomi | `mona` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `mona` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 41 43 44.5 47 | 39 41 45 47 48.5 51 |
| xiaomi | `mona` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 41 43 44.5 47 | 39 41 45 47 48.5 51 |
| xiaomi | `mona` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `mona` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `mona` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `mona` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `mona` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mona` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mona` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `mona` | `thermal-navigation.conf` | `NAV-MONITOR-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 41 42 43.5 47 | 39 43 45 46 47.5 51 |
| xiaomi | `mona` | `thermal-navigation.conf` | `NAV-MONITOR-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 41 42 43.5 47 | 39 43 45 46 47.5 51 |
| xiaomi | `mona` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `mona` | `thermal-normal.conf` | `MONITOR-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40.2 41 45 47 | 43 44.2 45 49 51 |
| xiaomi | `mona` | `thermal-normal.conf` | `MONITOR-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40.2 41 45 47 | 43 44.2 45 49 51 |
| xiaomi | `mona` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `mona` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `mona` | `thermal-tgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `mona` | `thermal-tgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mona` | `thermal-tgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `mona` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `mona` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 38.5 41 43 44.5 47 | 39 42.5 45 47 48.5 51 |
| xiaomi | `mona` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 38.5 41 43 44.5 47 | 39 42.5 45 47 48.5 51 |
| xiaomi | `mona` | `thermal-videochat.conf` | `videochat-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `mona` | `thermal-videochat.conf` | `videochat-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 36.5 38 40 42 46 | 40 41.5 43 45 47 51 |
| xiaomi | `mona` | `thermal-videochat.conf` | `videochat-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 36.5 38 40 42 46 | 40 41.5 43 45 47 51 |
| xiaomi | `mona` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `mona` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43.5 47 | 39 41 43 45 47.5 51 |
| xiaomi | `mona` | `thermal-youtube.conf` | `YTB-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43.5 47 | 39 41 43 45 47.5 51 |
| xiaomi | `mondrian` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mondrian` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `mondrian` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `mondrian` | `thermal-8k.conf` | `8K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mondrian` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-8k.conf` | `8K-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `mondrian` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `mondrian` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mondrian` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `mondrian` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `mondrian` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 37 39 41 43 44 45 46 47 48 | 28 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 37 39 41 43 44 45 46 47 48 | 28 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 37 39 41 43 44 45 46 47 48 | 28 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 37 39 41 43 44 45 46 47 48 | 28 40 42 44 46 47 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-cmgame.conf` | `CMGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-cmgame.conf` | `CMGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-cmgame.conf` | `CMGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-cmgame.conf` | `CMGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 39 46 | 44 51 |
| xiaomi | `mondrian` | `thermal-cmgame.conf` | `CMGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 39 46 | 44 51 |
| xiaomi | `mondrian` | `thermal-cyuanshen.conf` | `CYUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mondrian` | `thermal-cyuanshen.conf` | `CYUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-cyuanshen.conf` | `CYUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 48 | 42 51 |
| xiaomi | `mondrian` | `thermal-cyuanshen.conf` | `CYUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 48 | 42 51 |
| xiaomi | `mondrian` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `mondrian` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `mondrian` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 39 41 43 44 45 46 47 48 | 28 42 44 46 47 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `mondrian` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mondrian` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `mondrian` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 36 42.5 43.2 43.9 44.6 45.3 46 | 41 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mondrian` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mondrian` | `thermal-normal.conf` | `NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-normal.conf` | `NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-normal.conf` | `NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 39 41 43 44 45 46 47 48 | 28 42 44 46 47 48 49 50 51 |
| xiaomi | `mondrian` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-per-cclassvideo.conf` | `PER-CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-per-cgame.conf` | `PER-CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mondrian` | `thermal-per-cgame.conf` | `PER-CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-per-cgame.conf` | `PER-CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43.5 44.5 45.2 46.6 47.3 48 | 46.5 47.5 48.2 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-per-cgame.conf` | `PER-CGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43.5 44.5 45.2 46.6 47.3 48 | 46.5 47.5 48.2 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mondrian` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mondrian` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mondrian` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 25 35 45 46 | 30 40 50 51 |
| xiaomi | `mondrian` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 50 | 36 38 40 42 44 45 46 47 48 51 |
| xiaomi | `mondrian` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 50 | 36 38 40 42 44 45 46 47 48 51 |
| xiaomi | `mondrian` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `mondrian` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `mondrian` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 46.5 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43.5 44.5 45.2 45.9 46.6 47.3 48 | 46.5 47.5 48.2 48.9 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `mondrian` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 45 47 | 46 48 |
| xiaomi | `mondrian` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `mondrian` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `mondrian` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 46 | 45 48 |
| xiaomi | `mondrian` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mondrian` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `mondrian` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `mondrian` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `mondrian` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43.5 44.5 45.2 46.6 47.3 48 | 46.5 47.5 48.2 49.6 50.3 51 |
| xiaomi | `mondrian` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43.5 44.5 45.2 46.6 47.3 48 | 46.5 47.5 48.2 49.6 50.3 51 |
| xiaomi | `monet` | `thermal-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `monet` | `thermal-4k.conf` | `4k-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `monet` | `thermal-4k.conf` | `4k-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `monet` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `monet` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `monet` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `monet` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `monet` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `monet` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `monet` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `monet` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `monet` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `monet` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `monet` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `monet` | `thermal-normal.conf` | `MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 47 | 1 | 46 | 47 |
| xiaomi | `monet` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `monet` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `monet` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `monet` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `monet` | `thermal-phone.conf` | `PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `monet` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `monet` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 44 45 47 51 | 47 48 50 54 |
| xiaomi | `moon` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 38 41 44 | 41 44 47 |
| xiaomi | `moon` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 43.5 | 47.5 | 4 | 34 36 42.5 43.5 | 38 40 46.5 47.5 |
| xiaomi | `moon` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 42.5 | 46.5 | 4 | 34 36 40 42.5 | 38 40 44 46.5 |
| xiaomi | `moon` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 29 31 33 35 37 39 41 43 45 | 33 35 37 39 41 43 45 47 49 |
| xiaomi | `moon` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 29 31 33 35 37 39 41 43 45 | 33 35 37 39 41 43 45 47 49 |
| xiaomi | `moon` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 47 | 1 | 46 | 47 |
| xiaomi | `moon` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 43 44 45 | 47 48 49 |
| xiaomi | `moon` | `thermal-cgame.conf` | `CGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 43 44 45 | 47 48 49 |
| xiaomi | `moon` | `thermal-chg-only.conf` | `CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51.5 | 4 | 38 40 42 44 45 47.5 | 42 44 46 48 49 51.5 |
| xiaomi | `moon` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 47.5 | 51.5 | 4 | 36 38 40 42 44 45 47.5 | 40 42 44 46 48 49 51.5 |
| xiaomi | `moon` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `moon` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 32 34 36 37 40 43 46.5 | 36 38 40 41 44 47 50.5 |
| xiaomi | `moon` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 32 34 36 37 40 43 46.5 | 36 38 40 41 44 47 50.5 |
| xiaomi | `moon` | `thermal-douyin.conf` | `DOUYIN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-douyin.conf` | `DOUYIN-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 30 32 35 37 43 | 34 36 39 41 47 |
| xiaomi | `moon` | `thermal-douyin.conf` | `DOUYIN-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 30 32 35 37 43 | 34 36 39 41 47 |
| xiaomi | `moon` | `thermal-hp-game.conf` | `HP-GAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `moon` | `thermal-hp-game.conf` | `HP-GAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 41 43 | 45 47 |
| xiaomi | `moon` | `thermal-hp-game.conf` | `HP-GAME-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 37 38 39 40 41 42 | 41 42 43 44 45 46 |
| xiaomi | `moon` | `thermal-hp-game.conf` | `HP-GAME-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 36 37 38 39 40 41 42 | 40 41 42 43 44 45 46 |
| xiaomi | `moon` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `moon` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 40 41 43 | 44 45 47 |
| xiaomi | `moon` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 37 38 39 40 41 42 | 41 42 43 44 45 46 |
| xiaomi | `moon` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 36 37 38 39 40 41 42 | 40 41 42 43 44 45 46 |
| xiaomi | `moon` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 33 35 38 40 43 | 37 39 42 44 47 |
| xiaomi | `moon` | `thermal-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 33 35 38 40 43 | 37 39 42 44 47 |
| xiaomi | `moon` | `thermal-iqiyi.conf` | `IQIYI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-iqiyi.conf` | `IQIYI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 35 36 37 38 43 | 39 40 41 42 47 |
| xiaomi | `moon` | `thermal-iqiyi.conf` | `IQIYI-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 35 36 37 38 43 | 39 40 41 42 47 |
| xiaomi | `moon` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `moon` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 46.5 | 50 | 3.5 | 40 44 46.5 | 43.5 47.5 50 |
| xiaomi | `moon` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 35 39 40 41 42 | 39 43 44 45 46 |
| xiaomi | `moon` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 35 39 40 41 42 45 | 39 43 44 45 46 49 |
| xiaomi | `moon` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `moon` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 32 34.5 36.5 40 | 36 38.5 40.5 44 |
| xiaomi | `moon` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 32 34.5 36.5 40 | 36 38.5 40.5 44 |
| xiaomi | `moon` | `thermal-nolimits.conf` | `NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 45 | 47 |
| xiaomi | `moon` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51.5 | 4 | 38 40 42 44 45 47.5 | 42 44 46 48 49 51.5 |
| xiaomi | `moon` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47.5 | 51.5 | 4 | 36 38 40 42 44 45 47.5 | 40 42 44 46 48 49 51.5 |
| xiaomi | `moon` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `moon` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 45 | 47 |
| xiaomi | `moon` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 30 33.5 44 | 34 37.5 48 |
| xiaomi | `moon` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 30 33.5 44 | 34 37.5 48 |
| xiaomi | `moon` | `thermal-pubg.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `moon` | `thermal-pubg.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-pubg.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 35 39 40 41 42 43 46.5 | 39 43 44 45 46 47 50.5 |
| xiaomi | `moon` | `thermal-pubg.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 35 39 40 41 42 43 46.5 | 39 43 44 45 46 47 50.5 |
| xiaomi | `moon` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `moon` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 35 39 40 41 42 43 46.5 | 39 43 44 45 46 47 50.5 |
| xiaomi | `moon` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 50.5 | 4 | 35 39 40 41 42 43 46.5 | 39 43 44 45 46 47 50.5 |
| xiaomi | `moon` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 41 43 45 | 43 45 47 |
| xiaomi | `moon` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 30 32 35 37 43 | 34 36 39 41 47 |
| xiaomi | `moon` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 30 32 35 37 43 | 34 36 39 41 47 |
| xiaomi | `moon` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 47 | 3 | 42 44 | 45 47 |
| xiaomi | `moon` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 42.5 | 46.5 | 4 | 34 36 40 42.5 | 38 40 44 46.5 |
| xiaomi | `moon` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 42.5 | 46.5 | 4 | 34 36 40 42.5 | 38 40 44 46.5 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-camera.conf` | `CAM-MONITOR-GPU` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 40 41 42 | 45 46 47 |
| xiaomi | `moonstone` | `thermal-camera.conf` | `CAM-SS-SILVER` | `VIRTUAL-SENSOR` | 46 | 47 | 1 | 40 41 42 43.5 46 | 41 42 43 44.5 47 |
| xiaomi | `moonstone` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `moonstone` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `moonstone` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `moonstone` | `thermal-normal-india.conf` | `NORMAL-IN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `moonstone` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `moonstone` | `thermal-phone.conf` | `PHONE-SS-SILVER` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 27 32 42 | 32 37 47 |
| xiaomi | `moonstone` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `moonstone` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `moonstone` | `thermal-youtube.conf` | `YTB-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `munch` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `munch` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 46 48 | 38 40 42 44 46 48 49 51 |
| xiaomi | `munch` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `munch` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 46 48 | 38 40 42 44 46 48 49 51 |
| xiaomi | `munch` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 48 | 38 40 42 44 46 48 51 |
| xiaomi | `munch` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 48 | 38 40 42 44 46 48 51 |
| xiaomi | `munch` | `thermal-chg-only.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `munch` | `thermal-chg-only.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `munch` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `munch` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 34.5 35 39 41 43 44 45 | 16 36 40.5 41 45 47 49 50 51 |
| xiaomi | `munch` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 34 34.5 35 37 39 41 43 44 45 | 16 40 40.5 41 43 45 47 49 50 51 |
| xiaomi | `munch` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 46 | 3 | 35 37 39 41 43 | 38 40 42 44 46 |
| xiaomi | `munch` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 41 43 | 41 43 45 47 49 |
| xiaomi | `munch` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `munch` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 45.5 | 51 | 5.5 | 43.5 44.5 45.5 | 49 50 51 |
| xiaomi | `munch` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 45.5 | 51 | 5.5 | 43.5 44.5 45.5 | 49 50 51 |
| xiaomi | `munch` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 30 35 37 39 41 43 45 46 | 20 35 40 42 44 46 48 50 51 |
| xiaomi | `munch` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 30 35 37 39 41 43 45 46 | 20 35 40 42 44 46 48 50 51 |
| xiaomi | `munch` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `munch` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 37 39 41 42 45 46 47 48 | 18 38 40 42 44 45 48 49 50 51 |
| xiaomi | `munch` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 37 39 41 42 45 46 48 | 18 38 40 42 44 45 48 49 51 |
| xiaomi | `munch` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 42 43 45 48 | 40 42 44 45 46 48 51 |
| xiaomi | `munch` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 42 43 45 48 | 40 42 44 45 46 48 51 |
| xiaomi | `munch` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `munch` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `munch` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `munch` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 46 | 3 | 35 37 39 41 43 | 38 40 42 44 46 |
| xiaomi | `munch` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 41 43 | 41 43 45 47 49 |
| xiaomi | `munch` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `munch` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `munch` | `thermal-per-normal.conf` | `PER-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 25 35 45 | 28 38 48 |
| xiaomi | `munch` | `thermal-per-normal.conf` | `PER-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `munch` | `thermal-per-normal.conf` | `PER-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `munch` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `munch` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `munch` | `thermal-per-videochat.conf` | `PER-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-per-videochat.conf` | `PER-VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 42 43 45 46 47 48 | 40 42 44 45 46 48 49 50 51 |
| xiaomi | `munch` | `thermal-per-videochat.conf` | `PER-VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 42 43 45 46 48 | 40 42 44 45 46 48 49 51 |
| xiaomi | `munch` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `munch` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 39 41 43 45 | 31 45 47 49 51 |
| xiaomi | `munch` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 39 41 45 | 31 45 47 51 |
| xiaomi | `munch` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `munch` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `munch` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 30 35 37 39 41 43 44 45 | 21 36 41 43 45 47 49 50 51 |
| xiaomi | `munch` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 30 35 37 39 41 43 44 45 | 21 36 41 43 45 47 49 50 51 |
| xiaomi | `munch` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `munch` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 35 37 39 41 43 44 45 | 41 43 45 47 49 50 51 |
| xiaomi | `munch` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 35 37 39 41 43 45 | 41 43 45 47 49 51 |
| xiaomi | `nabu` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 30 46 | 35 51 |
| xiaomi | `nabu` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 30 46 | 35 51 |
| xiaomi | `nabu` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `nabu` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `nabu` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `nabu` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 47 48 | 41 44 46 48 50 51 |
| xiaomi | `odin` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `odin` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `odin` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `odin` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-chg-only.conf` | `CHG-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-chg-only.conf` | `CHG-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `odin` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `odin` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `odin` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 39 41 42 43 45 | 21 45 47 48 49 51 |
| xiaomi | `odin` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 39 41 42 43 45 | 21 45 47 48 49 51 |
| xiaomi | `odin` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `odin` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `odin` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `odin` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `odin` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `odin` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `odin` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `odin` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-per-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `odin` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 42 43 45 48 | 40 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 42 43 45 48 | 40 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-per-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-per-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 42 43 45 48 | 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-per-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 42 43 45 48 | 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 37 39 41 43 45 | 41 43 45 47 49 51 |
| xiaomi | `odin` | `thermal-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 37 39 41 43 45 | 41 43 45 47 49 51 |
| xiaomi | `odin` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 42 43 45 48 | 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 41 42 43 45 48 | 42 44 45 46 48 51 |
| xiaomi | `odin` | `thermal-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 37 39 41 43 45 | 41 43 45 47 49 51 |
| xiaomi | `odin` | `thermal-per-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 35 37 39 41 43 45 | 41 43 45 47 49 51 |
| xiaomi | `odin` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `odin` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `odin` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `odin` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `odin` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `odin` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `odin` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `odin` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `olive` | `thermal-engine-camera.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olive` | `thermal-engine-high.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olive` | `thermal-engine-normal.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olive` | `thermal-engine-sgame.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivelite` | `thermal-engine-camera.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivelite` | `thermal-engine-high.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivelite` | `thermal-engine-normal.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivelite` | `thermal-engine-sgame.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivewood` | `thermal-engine-camera.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivewood` | `thermal-engine-high.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivewood` | `thermal-engine-normal.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `olivewood` | `thermal-engine-sgame.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `onc` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-adc` | 46 | 51 | 5 | 40 42 44 45 46 | 45 47 49 50 51 |
| xiaomi | `onc` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `backlight-therm-adc` | 50 | 55 | 5 | 46 48 50 | 51 53 55 |
| xiaomi | `onc` | `thermal-engine-normal.conf` | `MONITOR-CPU-HOTPLUG` | `quiet-therm-adc` | 49 | 54 | 5 | 45 49 | 50 54 |
| xiaomi | `onc` | `thermal-engine-video.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-adc` | 46 | 51 | 5 | 40 42 44 45 46 | 45 47 49 50 51 |
| xiaomi | `onc` | `thermal-engine-video.conf` | `LCD_MONITOR` | `backlight-therm-adc` | 50 | 55 | 5 | 46 48 50 | 51 53 55 |
| xiaomi | `onc` | `thermal-engine-video.conf` | `MONITOR-CPU-HOTPLUG` | `quiet-therm-adc` | 49 | 54 | 5 | 45 49 | 50 54 |
| xiaomi | `opal` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `opal` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 40 42 44 46 48 | 45 47 49 51 53 |
| xiaomi | `opal` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 32 34 36 42 | 37 39 41 47 |
| xiaomi | `opal` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 32 34 36 42 | 37 39 41 47 |
| xiaomi | `opal` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `opal` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `opal` | `thermal-class0.conf` | `WEIBO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-class0.conf` | `WEIBO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-class0.conf` | `WEIBO-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 32 34 36 42 45 | 37 39 41 47 50 |
| xiaomi | `opal` | `thermal-class0.conf` | `WEIBO-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 32 34 36 42 45 | 37 39 41 47 50 |
| xiaomi | `opal` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 38 40 41 43 45 47 | 43 45 46 48 50 52 |
| xiaomi | `opal` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 38 40 41 43 45 47 | 43 45 46 48 50 52 |
| xiaomi | `opal` | `thermal-navigation.conf` | `NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-navigation.conf` | `NAVG-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-navigation.conf` | `NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `opal` | `thermal-navigation.conf` | `NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `opal` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `opal` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `opal` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `opal` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 36 38 40 42 44 46 48 50 | 41 43 45 47 49 51 53 55 |
| xiaomi | `opal` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 38 40 41 43 45 47 | 43 45 46 48 50 52 |
| xiaomi | `opal` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 38 40 41 43 45 47 | 43 45 46 48 50 52 |
| xiaomi | `opal` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 41 | 46 | 5 | 33 35 37 41 | 38 40 42 46 |
| xiaomi | `opal` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 41 | 46 | 5 | 33 35 37 41 | 38 40 42 46 |
| xiaomi | `opal` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `opal` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 45 | 46 50 |
| xiaomi | `opal` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `opal` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38 40 42 44 | 41 43 45 47 49 |
| xiaomi | `phoenix` | `thermal-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 38 44 51 | 41 47 54 |
| xiaomi | `phoenix` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `phoenix` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `phoenix` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `phoenix` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenix` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `phoenix` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 45 48 51 | 39 41 45 48 51 54 |
| xiaomi | `phoenix` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `phoenix` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenix` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenix` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenix` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `phoenix` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 45 48 51 | 39 41 45 48 51 54 |
| xiaomi | `phoenix` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `phoenix` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `phoenix` | `thermal-phone.conf` | `PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `phoenix` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `phoenixin` | `thermal-4k.conf` | `INDIA-4K-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 38 44 51 | 41 47 54 |
| xiaomi | `phoenixin` | `thermal-arvr.conf` | `INDIA-ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `phoenixin` | `thermal-arvr.conf` | `INDIA-ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `phoenixin` | `thermal-arvr.conf` | `INDIA-ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `phoenixin` | `thermal-camera.conf` | `INDIA-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenixin` | `thermal-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `phoenixin` | `thermal-camera.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 44 51 | 39 41 45 47 54 |
| xiaomi | `phoenixin` | `thermal-chg-only.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `phoenixin` | `thermal-nolimits.conf` | `INDIA-NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenixin` | `thermal-nolimits.conf` | `INDIA-NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenixin` | `thermal-normal.conf` | `INDIA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `phoenixin` | `thermal-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `phoenixin` | `thermal-normal.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 45 48 51 | 39 41 45 48 51 54 |
| xiaomi | `phoenixin` | `thermal-phone.conf` | `INDIA-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `phoenixin` | `thermal-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `phoenixin` | `thermal-phone.conf` | `INDIA-PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `phoenixin` | `thermal-tgame.conf` | `INDIA-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `picasso` | `thermal-4k.conf` | `4k-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `picasso` | `thermal-4k.conf` | `4k-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `picasso` | `thermal-4k.conf` | `4k-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 46 51 | 39 41 45 49 54 |
| xiaomi | `picasso` | `thermal-4k.conf` | `4k-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 46 51 | 39 41 45 49 54 |
| xiaomi | `picasso` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `picasso` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `picasso` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `picasso` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `picasso` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `picasso` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `picasso` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 46 51 | 39 41 45 49 54 |
| xiaomi | `picasso` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 46 51 | 39 41 45 49 54 |
| xiaomi | `picasso` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `picasso` | `thermal-chg-only.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `picasso` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `picasso` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `picasso` | `thermal-nolimits.conf` | `NL-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `picasso` | `thermal-nolimits.conf` | `NL-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `picasso` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `picasso` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `picasso` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 41 46 51 | 39 41 44 49 54 |
| xiaomi | `picasso` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 41 46 51 | 39 41 44 49 54 |
| xiaomi | `picasso` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `picasso` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `picasso` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `picasso` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `picasso` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `picasso` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `picasso` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 46 51 | 39 41 45 49 54 |
| xiaomi | `picasso` | `thermal-youtube.conf` | `YTB-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 46 51 | 39 41 45 49 54 |
| xiaomi | `pine` | `thermal-engine-camera.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `pine` | `thermal-engine-high.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `pine` | `thermal-engine-normal.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `pine` | `thermal-engine-sgame.conf` | `BACKLIGHT_AP_TEMP_MITIGATION` | `backlight-therm` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `pipa` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-4k.conf` | `4K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 39 42 45 | 40 44 47 50 |
| xiaomi | `pipa` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 37 39 41 43 45 46 47 48 | 40 42 44 46 48 50 51 52 53 |
| xiaomi | `pipa` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 37 39 41 43 45 46 48 | 40 42 44 46 48 50 51 53 |
| xiaomi | `pipa` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 39 42 45 | 40 44 47 50 |
| xiaomi | `pipa` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 45 | 20 50 |
| xiaomi | `pipa` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 25 38 39 41 43 44 45 47 48 | 30 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 28 39 40 41 43 44 45 48 | 33 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-cgame.conf` | `CGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 15 45 50 | 16 46 51 |
| xiaomi | `pipa` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `pipa` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 15 46 | 21 52 |
| xiaomi | `pipa` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 15 46 | 21 52 |
| xiaomi | `pipa` | `thermal-chg-only.conf` | `CHG-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `pipa` | `thermal-chg-only.conf` | `CHG-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `pipa` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 30 32 34 38 40 45 | 35 37 39 43 45 50 |
| xiaomi | `pipa` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-global-4k.conf` | `GLOBAL-4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-4k.conf` | `GLOBAL-4K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-4k.conf` | `GLOBAL-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 39 42 45 | 40 44 47 50 |
| xiaomi | `pipa` | `thermal-global-4k.conf` | `GLOBAL-4k-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 37 39 41 43 45 46 47 48 | 40 42 44 46 48 50 51 52 53 |
| xiaomi | `pipa` | `thermal-global-4k.conf` | `GLOBAL-4k-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 37 39 41 43 45 46 48 | 40 42 44 46 48 50 51 53 |
| xiaomi | `pipa` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 39 42 45 | 40 44 47 50 |
| xiaomi | `pipa` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-global-camera.conf` | `GLOBAL-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 45 | 20 50 |
| xiaomi | `pipa` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-global-class0.conf` | `GLOBAL-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-global-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `pipa` | `thermal-global-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `pipa` | `thermal-global-hp-mgame.conf` | `HP-GLOBAL-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-global-hp-mgame.conf` | `HP-GLOBAL-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-global-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 40 45 | 40 45 50 |
| xiaomi | `pipa` | `thermal-global-hp-normal.conf` | `HP-GLOBAL-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 53 | 6 | 38 39 41 43 44 45 47 | 44 45 47 49 50 51 53 |
| xiaomi | `pipa` | `thermal-global-hp-normal.conf` | `HP-GLOBAL-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 53 | 6 | 38 39 40 41 43 44 45 47 | 44 45 46 47 49 50 51 53 |
| xiaomi | `pipa` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 40 41 41.5 43 | 41 43 45 46 47 47.5 49 |
| xiaomi | `pipa` | `thermal-global-huanji.conf` | `GLOBAL-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 40 41 41.5 43 | 41 43 45 46 47 47.5 49 |
| xiaomi | `pipa` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `pipa` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-global-mgame.conf` | `GLOBAL-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-global-nolimits.conf` | `GLOBAL-NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-global-nolimits.conf` | `GLOBAL-NL-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `pipa` | `thermal-global-nolimits.conf` | `GLOBAL-NL-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `pipa` | `thermal-global-normal.conf` | `GLOBAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-normal.conf` | `GLOBAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-normal.conf` | `GLOBAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 40 45 | 40 45 50 |
| xiaomi | `pipa` | `thermal-global-normal.conf` | `GLOBAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-global-normal.conf` | `GLOBAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pipa` | `thermal-global-tgame.conf` | `GLOBAL-TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pipa` | `thermal-global-video.conf` | `GLOBAL-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-video.conf` | `GLOBAL-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-video.conf` | `GLOBAL-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 45 | 40 50 |
| xiaomi | `pipa` | `thermal-global-video.conf` | `GLOBAL-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-global-video.conf` | `GLOBAL-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-global-videochat.conf` | `GLOBAL-videochat-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-global-videochat.conf` | `GLOBAL-videochat-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-global-videochat.conf` | `GLOBAL-videochat-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 45 | 20 50 |
| xiaomi | `pipa` | `thermal-global-videochat.conf` | `GLOBAL-videochat-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 38 39 41 43 44 45 47 48 | 40 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-global-videochat.conf` | `GLOBAL-videochat-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-huanji.conf` | `HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 40 41 41.5 43 | 41 43 45 46 47 47.5 49 |
| xiaomi | `pipa` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 40 41 41.5 43 | 41 43 45 46 47 47.5 49 |
| xiaomi | `pipa` | `thermal-india-4k.conf` | `INDIA-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 39 42 45 | 40 44 47 50 |
| xiaomi | `pipa` | `thermal-india-4k.conf` | `INDIA-4k-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 37 39 41 43 45 46 47 48 | 40 42 44 46 48 50 51 52 53 |
| xiaomi | `pipa` | `thermal-india-4k.conf` | `INDIA-4k-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 37 39 41 43 45 46 48 | 40 42 44 46 48 50 51 53 |
| xiaomi | `pipa` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 39 42 45 | 40 44 47 50 |
| xiaomi | `pipa` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-india-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 45 | 20 50 |
| xiaomi | `pipa` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-india-huanji.conf` | `INDIA-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 40 41 41.5 43 | 41 43 45 46 47 47.5 49 |
| xiaomi | `pipa` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 43 | 49 | 6 | 35 37 39 40 41 41.5 43 | 41 43 45 46 47 47.5 49 |
| xiaomi | `pipa` | `thermal-india-mgame.conf` | `INDIA-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `pipa` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 40 45 | 40 45 50 |
| xiaomi | `pipa` | `thermal-india-normal.conf` | `INDIA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-india-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-india-tgame.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pipa` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pipa` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 45 | 40 50 |
| xiaomi | `pipa` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-india-videochat.conf` | `INDIA-videochat-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 45 | 20 50 |
| xiaomi | `pipa` | `thermal-india-videochat.conf` | `INDIA-videochat-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 38 39 41 43 44 45 47 48 | 40 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-india-videochat.conf` | `INDIA-videochat-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `pipa` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 52 | 6 | 46 | 52 |
| xiaomi | `pipa` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-nolimits.conf` | `NL-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `pipa` | `thermal-nolimits.conf` | `NL-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `pipa` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 40 45 | 40 45 50 |
| xiaomi | `pipa` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-tgame.conf` | `TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pipa` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pipa` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 35 45 | 40 50 |
| xiaomi | `pipa` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 41 43 44 45 47 48 | 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 45 | 20 50 |
| xiaomi | `pipa` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 35 38 39 41 43 44 45 47 48 | 40 43 44 46 48 49 50 52 53 |
| xiaomi | `pipa` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 38 39 40 41 43 44 45 48 | 43 44 45 46 48 49 50 53 |
| xiaomi | `pipa` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `pipa` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `pipa` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pipa` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pipa` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `pissarro` | `thermal-4k.conf` | `4K-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-camera.conf` | `CAMERA-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `pissarro` | `thermal-global-per-u-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `pissarro` | `thermal-global-per-u-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-global-per-u-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-global-per-u-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 38 40 41 42 43 45 46 47 | 40 42 44 45 46 47 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-per-u-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-per-u-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-global-per-u-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 40 41 42 43 44 45 46 47 | 41 43 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-per-u-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-per-u-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-global-per-u-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 41 42 43 45 | 44 46 47 48 50 |
| xiaomi | `pissarro` | `thermal-global-per-u-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-global-per-u-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-global-per-u-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-per-u-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-global-per-u-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 37 39 41 43 44 45 46 | 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-per-u-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-per-u-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-per-u-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-per-u-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-u-4k.conf` | `4K-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-global-u-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-global-u-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `pissarro` | `thermal-global-u-camera.conf` | `CAMERA-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-global-u-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 46 47 | 41 43 45 47 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-u-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-global-u-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-u-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-global-u-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 39 41 42 | 20 44 46 47 |
| xiaomi | `pissarro` | `thermal-global-u-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-mgame.conf` | `MGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `pissarro` | `thermal-global-u-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-global-u-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-global-u-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 37 39 41 43 44 45 46 | 20 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-u-nolimits.conf` | `NL-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-global-u-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-global-u-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `pissarro` | `thermal-global-u-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-global-u-phone.conf` | `PHONE-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `pissarro` | `thermal-global-u-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-tgame.conf` | `TGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-global-u-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `pissarro` | `thermal-global-u-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-global-u-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 39 41 42 | 20 44 46 47 |
| xiaomi | `pissarro` | `thermal-india-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `pissarro` | `thermal-india-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 43 45 47 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-india-camera.conf` | `CAMERA-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-india-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 39 41 42 | 20 44 46 47 |
| xiaomi | `pissarro` | `thermal-india-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-mgame.conf` | `MGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `pissarro` | `thermal-india-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `pissarro` | `thermal-india-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-india-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 37 39 41 43 44 45 46 | 20 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-nolimits.conf` | `NL-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 46 47 48 | 18 42 44 45 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-per-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-per-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 40 41 42 43 44 45 46 47 | 41 43 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-per-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 41 42 43 45 | 44 46 47 48 50 |
| xiaomi | `pissarro` | `thermal-india-per-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-per-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-india-per-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-per-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 37 39 41 43 44 45 46 | 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-u-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-per-u-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-u-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-u-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-per-u-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 40 41 42 43 44 45 46 47 | 41 43 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-u-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-u-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-per-u-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 41 42 43 45 | 44 46 47 48 50 |
| xiaomi | `pissarro` | `thermal-india-per-u-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-per-u-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-india-per-u-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-u-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-per-u-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 37 39 41 43 44 45 46 | 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-u-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-u-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-u-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-u-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-u-videochat.conf` | `VIDEOCHAT-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-u-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-per-u-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 36 38 40 41 42 43 45 48 | 39 41 43 44 45 46 48 51 |
| xiaomi | `pissarro` | `thermal-india-per-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-per-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-per-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-per-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 36 38 40 41 42 43 45 48 | 39 41 43 44 45 46 48 51 |
| xiaomi | `pissarro` | `thermal-india-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-india-phone.conf` | `PHONE-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `pissarro` | `thermal-india-tgame.conf` | `TGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-4k.conf` | `4K-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-u-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-camera.conf` | `CAMERA-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-u-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-u-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-u-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 39 41 42 | 20 44 46 47 |
| xiaomi | `pissarro` | `thermal-india-u-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-u-mgame.conf` | `MGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `pissarro` | `thermal-india-u-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `pissarro` | `thermal-india-u-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-u-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-india-u-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-u-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 37 39 41 43 44 45 46 | 20 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-nolimits.conf` | `NL-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-india-u-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 46 47 48 | 18 42 44 45 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-u-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-india-u-phone.conf` | `PHONE-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `pissarro` | `thermal-india-u-tgame.conf` | `TGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-india-u-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-u-videochat.conf` | `VIDEOCHAT-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-u-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 15 41 43 45 | 18 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-u-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 30 35 37 39 41 43 45 | 20 35 40 42 44 46 48 50 |
| xiaomi | `pissarro` | `thermal-india-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-india-videochat.conf` | `VIDEOCHAT-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-india-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 15 41 43 45 | 18 44 46 48 |
| xiaomi | `pissarro` | `thermal-india-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 15 30 35 37 39 41 43 45 | 20 35 40 42 44 46 48 50 |
| xiaomi | `pissarro` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-mgame.conf` | `MGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `pissarro` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `pissarro` | `thermal-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 37 39 41 43 44 45 46 | 20 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-nolimits.conf` | `NL-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 46 47 48 | 18 42 44 45 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-per-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-per-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-per-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `pissarro` | `thermal-per-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-per-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 41 42 43 45 | 44 46 47 48 50 |
| xiaomi | `pissarro` | `thermal-per-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-per-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-per-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-per-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 37 39 41 43 44 45 46 | 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-per-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-per-u-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-per-u-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-per-u-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-u-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-per-u-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `pissarro` | `thermal-per-u-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-u-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-per-u-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 39 41 42 43 45 | 44 46 47 48 50 |
| xiaomi | `pissarro` | `thermal-per-u-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-per-u-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-per-u-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-u-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-per-u-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 37 39 41 43 44 45 46 | 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-per-u-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-u-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-per-u-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-u-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-per-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-per-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-phone.conf` | `PHONE-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `pissarro` | `thermal-tgame.conf` | `TGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `pissarro` | `thermal-u-4k.conf` | `4K-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-u-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-u-camera.conf` | `CAMERA-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `pissarro` | `thermal-u-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `pissarro` | `thermal-u-class0.conf` | `CLASS0-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-u-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `pissarro` | `thermal-u-huanji.conf` | `HUANJI-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-u-huanji.conf` | `HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 39 41 42 | 20 44 46 47 |
| xiaomi | `pissarro` | `thermal-u-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-u-mgame.conf` | `MGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `pissarro` | `thermal-u-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `pissarro` | `thermal-u-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-u-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-u-navigation.conf` | `NAV-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-u-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 37 39 41 43 44 45 46 | 20 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-u-nolimits.conf` | `NL-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-normal.conf` | `MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 20 | 5 | 15 | 20 |
| xiaomi | `pissarro` | `thermal-u-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 46 47 48 | 18 42 44 45 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-u-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-u-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `pissarro` | `thermal-u-phone.conf` | `PHONE-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `pissarro` | `thermal-u-tgame.conf` | `TGAME-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `pissarro` | `thermal-u-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `pissarro` | `thermal-u-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-u-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `pissarro` | `thermal-video.conf` | `VIDEO-MONITOR-CPU` | `CPU_SOC` | 85 | 90 | 5 | 85 | 90 |
| xiaomi | `pissarro` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 35 37 39 41 43 44 45 46 | 20 40 42 44 46 48 49 50 51 |
| xiaomi | `psyche` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 43 44 45 | 16 36 41 43 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `psyche` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 34 34.5 35 39 41 43 44 45 | 16 36 40 40.5 41 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 34 34.5 35 37 39 41 43 44 45 | 16 36 40 40.5 41 43 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 41 41.8 | 47 47.8 |
| xiaomi | `psyche` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 35 37 39 40 41 41.5 41.8 | 41 43 45 46 47 47.5 47.8 |
| xiaomi | `psyche` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 35 37 39 40 41 41.5 41.8 | 41 43 45 46 47 47.5 47.8 |
| xiaomi | `psyche` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `psyche` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `psyche` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `psyche` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `psyche` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `psyche` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 34 34.5 35 39 41 43 44 45 | 16 36 40 40.5 41 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 34 34.5 35 37 39 41 43 44 45 | 16 36 40 40.5 41 43 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 25 35 45 | 28 38 48 |
| xiaomi | `psyche` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 37 39 41 42 45 46 47 48 | 18 38 40 42 44 45 48 49 50 51 |
| xiaomi | `psyche` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 37 39 41 42 45 46 48 | 18 38 40 42 44 45 48 49 51 |
| xiaomi | `psyche` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `psyche` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `psyche` | `thermal-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `psyche` | `thermal-per-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 41 41.8 | 47 47.8 |
| xiaomi | `psyche` | `thermal-per-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 35 37 39 40 41 41.5 41.8 | 41 43 45 46 47 47.5 47.8 |
| xiaomi | `psyche` | `thermal-per-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 41.8 | 47.8 | 6 | 35 37 39 40 41 41.5 41.8 | 41 43 45 46 47 47.5 47.8 |
| xiaomi | `psyche` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `psyche` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `psyche` | `thermal-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `psyche` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 25 35 45 | 28 38 48 |
| xiaomi | `psyche` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `psyche` | `thermal-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `psyche` | `thermal-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `psyche` | `thermal-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `psyche` | `thermal-per-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 48 | 38 40 42 44 45 46 48 49 51 |
| xiaomi | `psyche` | `thermal-per-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR-CAM` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `psyche` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `psyche` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 36 41 43 45 | 31 42 47 49 51 |
| xiaomi | `psyche` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 36 41 45 | 31 42 47 51 |
| xiaomi | `psyche` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `psyche` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `psyche` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 39 42 45 | 38 42 45 48 |
| xiaomi | `psyche` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 30 34 34.5 35 39 41 43 44 45 | 21 36 40 40.5 41 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 30 34 34.5 35 37 39 41 43 44 45 | 21 36 40 40.5 41 43 45 47 49 50 51 |
| xiaomi | `psyche` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR-CAM` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `psyche` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR-CAM` | 45 | 48 | 3 | 10 30 34 34.5 35 39 41 43 44 45 | 13 33 37 37.5 38 42 44 46 47 48 |
| xiaomi | `psyche` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR-CAM` | 45 | 48 | 3 | 10 30 34 34.5 35 37 39 41 43 44 45 | 13 33 37 37.5 38 40 42 44 46 47 48 |
| xiaomi | `raphael` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphael` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphael` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphael` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphael` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `raphael` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `raphael` | `thermal-extreme.conf` | `EXTREME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphael` | `thermal-extreme.conf` | `EXTREME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphael` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `raphael` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `raphael` | `thermal-youtobe.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `raphaelin` | `thermal-arvr.conf` | `INDIA-ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphaelin` | `thermal-arvr.conf` | `INDIA-ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphaelin` | `thermal-arvr.conf` | `INDIA-ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphaelin` | `thermal-arvr.conf` | `INDIA-ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphaelin` | `thermal-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `raphaelin` | `thermal-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `raphaelin` | `thermal-extreme.conf` | `INDIA-EXTREME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphaelin` | `thermal-extreme.conf` | `INDIA-EXTREME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 17 | 6 | 11 | 17 |
| xiaomi | `raphaelin` | `thermal-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `raphaelin` | `thermal-phone.conf` | `INDIA-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `raphaelin` | `thermal-youtobe.conf` | `INDIA-YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 43 45 48 | 46 48 51 |
| xiaomi | `redwood` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-4k.conf` | `4K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-4k.conf` | `4k-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 38 40 41 42 43.5 48 | 40 41 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-4k.conf` | `4k-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 41 42 43.5 48 | 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 40 41 42 43.5 48 | 40 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 40 41 42 43.5 48 | 40 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 39 41 42 43.5 49 | 41 43 44 45.5 51 |
| xiaomi | `redwood` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40.2 43 44.5 48 | 38 40 42 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40.2 43 44.5 48 | 38 40 42 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `redwood` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `redwood` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-hp-mgame.conf` | `HP-GLOBAL-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 40.2 41 45 47 | 39 43 44.2 45 49 51 |
| xiaomi | `redwood` | `thermal-hp-normal.conf` | `HP-GLOBAL-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 40.2 41 45 47 | 39 43 44.2 45 49 51 |
| xiaomi | `redwood` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-huanji.conf` | `HUANJI-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 42 | 48 |
| xiaomi | `redwood` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `redwood` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `redwood` | `thermal-india-4k.conf` | `INDIA-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-india-4k.conf` | `INDIA-4k-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 38 40 41 42 43.5 48 | 40 41 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-india-4k.conf` | `INDIA-4k-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 41 42 43.5 48 | 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 40 41 42 43.5 48 | 40 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 40 41 42 43.5 48 | 40 43 44 45 46.5 51 |
| xiaomi | `redwood` | `thermal-india-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40.2 43 44.5 48 | 38 40 42 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40.2 43 44.5 48 | 38 40 42 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-india-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-india-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-india-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-india-huanji.conf` | `INDIA-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 42 | 48 |
| xiaomi | `redwood` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `redwood` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `redwood` | `thermal-india-mgame.conf` | `INDIA-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `redwood` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-india-navigation.conf` | `INDIA-NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-india-navigation.conf` | `INDIA-NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 39 40.2 42 43.5 48 | 18 38 42 43.2 45 46.5 51 |
| xiaomi | `redwood` | `thermal-india-navigation.conf` | `INDIA-NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 39 40.2 42 43.5 48 | 18 38 42 43.2 45 46.5 51 |
| xiaomi | `redwood` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-india-normal.conf` | `INDIA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 39 40.2 41 45 48 | 38 42 43.2 44 48 51 |
| xiaomi | `redwood` | `thermal-india-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 39 40.2 41 45 48 | 38 42 43.2 44 48 51 |
| xiaomi | `redwood` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `redwood` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `redwood` | `thermal-india-tgame.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `redwood` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40.5 44.5 45.7 46.9 48 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40.5 44.5 45.7 46.9 48 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-india-videochat.conf` | `INDIA-videochat-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-india-videochat.conf` | `INDIA-videochat-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36.5 38 40 42 48 | 28 38 39.5 41 43 45 51 |
| xiaomi | `redwood` | `thermal-india-videochat.conf` | `INDIA-videochat-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36.5 38 40 42 48 | 28 38 39.5 41 43 45 51 |
| xiaomi | `redwood` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `redwood` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `redwood` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `redwood` | `thermal-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 39 40.2 42 43.5 48 | 18 38 42 43.2 45 46.5 51 |
| xiaomi | `redwood` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 35 39 40.2 42 43.5 48 | 18 38 42 43.2 45 46.5 51 |
| xiaomi | `redwood` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 39 40.2 41 45 48 | 38 42 43.2 44 48 51 |
| xiaomi | `redwood` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 39 40.2 41 45 48 | 38 42 43.2 44 48 51 |
| xiaomi | `redwood` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `redwood` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `redwood` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `redwood` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `redwood` | `thermal-tgame.conf` | `TGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `redwood` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40.5 44.5 45.7 46.9 48 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40.5 44.5 45.7 46.9 48 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `redwood` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `redwood` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 38.5 40.2 43 44.5 48 | 38 41.5 43.2 46 47.5 51 |
| xiaomi | `redwood` | `thermal-videochat.conf` | `videochat-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `redwood` | `thermal-videochat.conf` | `videochat-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `redwood` | `thermal-videochat.conf` | `videochat-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `redwood` | `thermal-videochat.conf` | `videochat-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36.5 38 40 42 48 | 28 38 39.5 41 43 45 51 |
| xiaomi | `redwood` | `thermal-videochat.conf` | `videochat-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 35 36.5 38 40 42 48 | 28 38 39.5 41 43 45 51 |
| xiaomi | `renoir` | `thermal-4k.conf` | `4k-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 40 41 42 43.5 49 | 42 43 44 45.5 51 |
| xiaomi | `renoir` | `thermal-4k.conf` | `4k-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 40 41 42 43.5 49 | 42 43 44 45.5 51 |
| xiaomi | `renoir` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 40 41 42 43.5 49 | 42 43 44 45.5 51 |
| xiaomi | `renoir` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 40 41 42 43.5 49 | 42 43 44 45.5 51 |
| xiaomi | `renoir` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 40 41 42 43.5 46 | 45 46 47 48.5 51 |
| xiaomi | `renoir` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 40 41 42 43.5 46 | 45 46 47 48.5 51 |
| xiaomi | `renoir` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 44 | 46 48 |
| xiaomi | `renoir` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-india-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `renoir` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `renoir` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `renoir` | `thermal-india-youtube.conf` | `INDIA-YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `renoir` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 44 | 46 48 |
| xiaomi | `renoir` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 42 44 | 48 50 |
| xiaomi | `renoir` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 42 44 | 48 50 |
| xiaomi | `renoir` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 44 | 46 48 |
| xiaomi | `renoir` | `thermal-navigation.conf` | `NAV-MONITOR-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-navigation.conf` | `NAV-MONITOR-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 44 | 46 48 |
| xiaomi | `renoir` | `thermal-normal.conf` | `MONITOR-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-normal.conf` | `MONITOR-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 27 48 | 30 51 |
| xiaomi | `renoir` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 44 | 46 48 |
| xiaomi | `renoir` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 42 44 | 48 50 |
| xiaomi | `renoir` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 42 44 | 48 50 |
| xiaomi | `renoir` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `renoir` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 40 41 42 44 | 46 47 48 50 |
| xiaomi | `renoir` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `renoir` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 40 41 42 43 49 | 42 43 44 45 51 |
| xiaomi | `renoir` | `thermal-youtube.conf` | `YTB-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 40 41 42 43 49 | 42 43 44 45 51 |
| xiaomi | `riva` | `thermal-engine-normal-india.conf` | `BATTERY_CHARGING_CTL` | `xo_therm` | 48 | 53 | 5 | 45 48 | 50 53 |
| xiaomi | `riva` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL` | `xo_therm` | 48 | 53 | 5 | 45 48 | 50 53 |
| xiaomi | `riva` | `thermal-engine-normal.conf` | `TEMP_STATE_CTL` | `xo_therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `rolex` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `pop_mem` | 48 | 53 | 5 | 44 48 | 49 53 |
| xiaomi | `rolex` | `thermal-engine.conf` | `CAMERA_CAMCORDER_MONITOR` | `pop_mem` | 48 | 53 | 5 | 45 48 | 50 53 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `MONITOR-CPU1` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `MONITOR-CPU2` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `MONITOR-CPU3` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `MONITOR-CPU5` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 42 | 46 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `MONITOR-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `SS-CPU0-1` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `SS-CPU0-2` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 43 | 47 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `SS-CPU6-1` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `rosemary` | `thermal-camera.conf` | `SS-CPU6-2` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `rosemary` | `thermal-camera2.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `rosemary` | `thermal-camera2.conf` | `SS-CPU0-1` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 51 | 55 |
| xiaomi | `rosemary` | `thermal-camera2.conf` | `SS-CPU0-2` | `VIRTUAL-SENSOR` | 53 | 55 | 2 | 53 | 55 |
| xiaomi | `rosemary` | `thermal-camera2.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 49 | 53 |
| xiaomi | `rosemary` | `thermal-camera2.conf` | `SS-CPU6-1` | `VIRTUAL-SENSOR` | 51 | 55 | 4 | 51 | 55 |
| xiaomi | `rosemary` | `thermal-camera2.conf` | `SS-CPU6-2` | `VIRTUAL-SENSOR` | 52 | 55 | 3 | 52 | 55 |
| xiaomi | `rosemary` | `thermal-chg-only.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `rosemary` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `rosemary` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 45.5 | 49.5 | 4 | 45.5 | 49.5 |
| xiaomi | `rosemary` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `rosemary` | `thermal-phone.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 44 | 4 | 40 | 44 |
| xiaomi | `rosemary` | `thermal-phone.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `MONITOR-CPU2` | `VIRTUAL-SENSOR` | 49 | 52 | 3 | 49 | 52 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `MONITOR-CPU3` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `MONITOR-CPU5` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `SS-CPU0-1` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `SS-CPU0-2` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `SS-CPU6-1` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `rosemary` | `thermal-tgame.conf` | `SS-CPU6-2` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 49 | 53 |
| xiaomi | `rosy` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `xo_therm` | 47 | 52 | 5 | 39 42 44 47 | 44 47 49 52 |
| xiaomi | `rosy` | `thermal-engine_india.conf` | `BATTERY_CHARGING_CTL` | `xo_therm` | 45 | 50 | 5 | 38 40 43 45 | 43 45 48 50 |
| xiaomi | `ruan` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `ruan` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 41 43 45 47 | 45 47 49 51 |
| xiaomi | `ruan` | `thermal-chg-only.conf` | `CHG-ONLY-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 43 45 46.5 47.5 | 42.5 44.5 46.5 48.5 50 51 |
| xiaomi | `ruan` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 43 45 46.5 47.5 | 42.5 44.5 46.5 48.5 50 51 |
| xiaomi | `ruan` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ruan` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `ruan` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 46 47 | 49 50 51 |
| xiaomi | `ruan` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 41 43 45 46 47 | 45 47 49 50 51 |
| xiaomi | `ruan` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 43 44 46 47 | 44 46 47 48 50 51 |
| xiaomi | `ruan` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ruan` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 47 | 49 |
| xiaomi | `ruan` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 45 46 47 | 49 50 51 |
| xiaomi | `ruan` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 41 43 45 47 | 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 35 37 39 41 43 | 40 42 44 46 48 |
| xiaomi | `ruan` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 36 38 40 42 43 | 41 43 45 47 48 |
| xiaomi | `ruan` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 41 43 44 45 46 | 46 48 49 50 51 |
| xiaomi | `ruan` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 40 42 43 44 45 46 | 45 47 48 49 50 51 |
| xiaomi | `ruan` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 41 43 45 47 | 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-normal.conf` | `NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 39 41 43 45 46.5 47.5 | 42.5 44.5 46.5 48.5 50 51 |
| xiaomi | `ruan` | `thermal-normal.conf` | `NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 39 41 43 | 44 46 48 |
| xiaomi | `ruan` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 33 47 | 37 51 |
| xiaomi | `ruan` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 34 47 | 38 51 |
| xiaomi | `ruan` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 41 43 44 45 46 | 46 48 49 50 51 |
| xiaomi | `ruan` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 40 42 43 44 45 46 | 45 47 48 49 50 51 |
| xiaomi | `ruan` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruan` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 45 47 48 | 48 50 51 |
| xiaomi | `ruan` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 43 45 | 42 44 46 48 50 |
| xiaomi | `ruan` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 38 40 42 44 45 | 43 45 47 49 50 |
| xiaomi | `ruby` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `ruby` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `ruby` | `thermal-chg-only-1.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 43 46 48 | 41 46 49 51 |
| xiaomi | `ruby` | `thermal-chg-only-3.conf` | `U-200-CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 43 46 48 | 41 46 49 51 |
| xiaomi | `ruby` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 43 46 48 | 41 46 49 51 |
| xiaomi | `ruby` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruby` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-4k.conf` | `GL-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-gl-4k.conf` | `GL-4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `ruby` | `thermal-gl-camera.conf` | `GL-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-gl-camera.conf` | `GL-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `ruby` | `thermal-gl-class0.conf` | `GL-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruby` | `thermal-gl-dolbyvision.conf` | `GL-DOLBYVISION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-hp-mgame.conf` | `GL-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-gl-hp-mgame.conf` | `GL-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-gl-hp-mgame.conf` | `GL-HP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-gl-hp-normal.conf` | `GL-HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 46 47 48 | 18 42 44 45 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-mgame.conf` | `GL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-gl-mgame.conf` | `GL-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-gl-navigation.conf` | `GL-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-gl-navigation.conf` | `GL-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-normal.conf` | `GL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-per-class0.conf` | `GL-PER-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `ruby` | `thermal-gl-per-normal.conf` | `GL-PER-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-per-video.conf` | `GL-PER-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-phone.conf` | `GL-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-gl-phone.conf` | `GL-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `ruby` | `thermal-gl-tgame.conf` | `GL-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-gl-tgame.conf` | `GL-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-video.conf` | `GL-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-gl-videochat.conf` | `GL-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `ruby` | `thermal-in-4k.conf` | `IN-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-in-4k.conf` | `IN-4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `ruby` | `thermal-in-camera.conf` | `IN-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-in-camera.conf` | `IN-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `ruby` | `thermal-in-class0.conf` | `IN-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruby` | `thermal-in-mgame.conf` | `IN-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-in-mgame.conf` | `IN-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-in-navigation.conf` | `IN-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-in-navigation.conf` | `IN-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-in-navigation.conf` | `IN-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-in-normal.conf` | `IN-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-in-per-class0.conf` | `IN-PER-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `ruby` | `thermal-in-per-normal.conf` | `IN-PER-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `ruby` | `thermal-in-per-video.conf` | `IN-PER-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-in-phone.conf` | `IN-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-in-phone.conf` | `IN-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `ruby` | `thermal-in-tgame.conf` | `IN-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-in-tgame.conf` | `IN-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `ruby` | `thermal-in-video.conf` | `IN-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-in-videochat.conf` | `IN-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `ruby` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `ruby` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `ruby` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `ruby` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-4k.conf` | `U-200-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-200-4k.conf` | `U-200-4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-200-camera.conf` | `U-200-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-200-camera.conf` | `U-200-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-200-class0.conf` | `U-200-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruby` | `thermal-u-200-dolbyvision.conf` | `U-200-DOLBYVISION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-huanji.conf` | `U-200-HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 33 35 37 39 41 42 | 20 38 40 42 44 46 47 |
| xiaomi | `ruby` | `thermal-u-200-mgame.conf` | `U-200-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-200-mgame.conf` | `U-200-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-u-200-mgame.conf` | `U-200-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-u-200-navigation.conf` | `U-200-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-200-navigation.conf` | `U-200-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-200-navigation.conf` | `U-200-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-normal.conf` | `U-200-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 42 43 45 46 47 48 | 38 40 42 44 45 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-per-class0.conf` | `U-200-PER-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `ruby` | `thermal-u-200-per-normal.conf` | `U-200-PER-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 42 43 44 45 46 47 48 | 42 44 45 46 47 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-per-video.conf` | `U-200-PER-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-phone.conf` | `U-200-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-200-phone.conf` | `U-200-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-200-phone.conf` | `U-200-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `ruby` | `thermal-u-200-tgame.conf` | `U-200-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-200-tgame.conf` | `U-200-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-video.conf` | `U-200-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-200-videochat.conf` | `U-200-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `ruby` | `thermal-u-4k.conf` | `U-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-4k.conf` | `U-4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-camera.conf` | `U-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-camera.conf` | `U-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-class0.conf` | `U-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruby` | `thermal-u-dolbyvision.conf` | `U-DOLBYVISION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-4k.conf` | `U-GL-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-gl-4k.conf` | `U-GL-4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-camera.conf` | `U-GL-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-gl-camera.conf` | `U-GL-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-class0.conf` | `U-GL-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruby` | `thermal-u-gl-dolbyvision.conf` | `U-GL-DOLBYVISION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-hp-mgame.conf` | `U-GL-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-gl-hp-mgame.conf` | `U-GL-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-u-gl-hp-mgame.conf` | `U-GL-HP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-u-gl-hp-normal.conf` | `U-GL-HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 46 47 48 | 18 42 44 45 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-huanji.conf` | `U-GL-HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 33 35 37 39 41 42 | 20 38 40 42 44 46 47 |
| xiaomi | `ruby` | `thermal-u-gl-mgame.conf` | `U-GL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-gl-mgame.conf` | `U-GL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-u-gl-mgame.conf` | `U-GL-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-u-gl-navigation.conf` | `U-GL-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-gl-navigation.conf` | `U-GL-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-gl-navigation.conf` | `U-GL-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-per-class0.conf` | `U-GL-PER-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `ruby` | `thermal-u-gl-per-video.conf` | `U-GL-PER-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-phone.conf` | `U-GL-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-gl-phone.conf` | `U-GL-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-gl-phone.conf` | `U-GL-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `ruby` | `thermal-u-gl-tgame.conf` | `U-GL-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-gl-tgame.conf` | `U-GL-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-video.conf` | `U-GL-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-gl-videochat.conf` | `U-GL-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `ruby` | `thermal-u-huanji.conf` | `U-HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 33 35 37 39 41 42 | 20 38 40 42 44 46 47 |
| xiaomi | `ruby` | `thermal-u-in-4k.conf` | `U-IN-4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-in-4k.conf` | `U-IN-4K-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 36 38 40 41 42 43 45 48 49 | 38 40 42 43 44 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-in-camera.conf` | `U-IN-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ruby` | `thermal-u-in-camera.conf` | `U-IN-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 37 39 41 43 45 48 49 | 39 41 43 45 47 50 51 |
| xiaomi | `ruby` | `thermal-u-in-class0.conf` | `U-IN-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `ruby` | `thermal-u-in-dolbyvision.conf` | `U-IN-DOLBYVISION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-in-huanji.conf` | `U-IN-HUANJI-SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 15 33 35 37 39 41 42 | 20 38 40 42 44 46 47 |
| xiaomi | `ruby` | `thermal-u-in-mgame.conf` | `U-IN-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-in-mgame.conf` | `U-IN-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-u-in-mgame.conf` | `U-IN-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-u-in-navigation.conf` | `U-IN-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-in-navigation.conf` | `U-IN-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-in-navigation.conf` | `U-IN-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-in-per-class0.conf` | `U-IN-PER-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `ruby` | `thermal-u-in-per-video.conf` | `U-IN-PER-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-in-phone.conf` | `U-IN-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-in-phone.conf` | `U-IN-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-in-phone.conf` | `U-IN-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `ruby` | `thermal-u-in-tgame.conf` | `U-IN-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-in-tgame.conf` | `U-IN-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `ruby` | `thermal-u-in-video.conf` | `U-IN-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-in-videochat.conf` | `U-IN-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `ruby` | `thermal-u-mgame.conf` | `U-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-mgame.conf` | `U-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `ruby` | `thermal-u-mgame.conf` | `U-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `ruby` | `thermal-u-navigation.conf` | `U-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-navigation.conf` | `U-NAVIGATION-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-navigation.conf` | `U-NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-per-class0.conf` | `U-PER-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 48 | 42 44 46 48 49 51 |
| xiaomi | `ruby` | `thermal-u-per-video.conf` | `U-PER-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-phone.conf` | `U-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-phone.conf` | `U-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ruby` | `thermal-u-phone.conf` | `U-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 27 45 | 32 50 |
| xiaomi | `ruby` | `thermal-u-tgame.conf` | `U-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ruby` | `thermal-u-tgame.conf` | `U-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 46 47 48 | 49 50 51 |
| xiaomi | `ruby` | `thermal-u-video.conf` | `U-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-u-videochat.conf` | `U-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `ruby` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `ruby` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 39 41 42 43 45 46 47 | 19 43 45 46 47 49 50 51 |
| xiaomi | `santoni` | `thermal-engine.conf` | `BATTERY_CHARGING_CTL` | `case_therm` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `santoni` | `thermal-engine.conf` | `CAMERA_CAMCORDER_MONITOR` | `case_therm` | 45 | 50 | 5 | 43 45 | 48 50 |
| xiaomi | `santoni` | `thermal-engine.conf` | `CPU1_HOTPLUG_MONITOR` | `case_therm` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `santoni` | `thermal-engine.conf` | `CPU2_HOTPLUG_MONITOR` | `case_therm` | 43 | 48 | 5 | 43 | 48 |
| xiaomi | `santoni` | `thermal-engine.conf` | `CPU5_HOTPLUG_MONITOR` | `case_therm` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `sea` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 42 44 46 51 | 45 47 49 54 |
| xiaomi | `sea` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51.5 | 53 | 1.5 | 42.5 44.5 46.5 51.5 | 44 46 48 53 |
| xiaomi | `sea` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 40 42 44.5 45.5 46.5 47.5 49 51 | 43 45 47.5 48.5 49.5 50.5 52 54 |
| xiaomi | `sea` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 39 41 43 44 45 48 50 | 42 44 46 47 48 51 53 |
| xiaomi | `sea` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 52 | 54 | 2 | 41 42 43 45 50 52 | 43 44 45 47 52 54 |
| xiaomi | `sea` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 44 46 48 49 51 | 46 48 50 51 53 |
| xiaomi | `sea` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `sea` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 44 46 48 50 | 48 50 52 54 |
| xiaomi | `sea` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 43 45 47 49 | 47 49 51 53 |
| xiaomi | `sea` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 42 44 46 51 | 45 47 49 54 |
| xiaomi | `sea` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 51.5 | 53 | 1.5 | 42.5 44.5 46.5 51.5 | 44 46 48 53 |
| xiaomi | `sea` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `sea` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 44 46 48 50 | 48 50 52 54 |
| xiaomi | `sea` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 43 45 47 49 | 47 49 51 53 |
| xiaomi | `sea` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 38 40 42.5 43.5 44.5 45.5 47 49 | 42 44 46.5 47.5 48.5 49.5 51 53 |
| xiaomi | `sea` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 37 39 41 42 43 46 48 | 41 43 45 46 47 50 52 |
| xiaomi | `sea` | `thermal-normal.conf` | `NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-normal.conf` | `NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 52 | 54 | 2 | 41 42 43 45 50 52 | 43 44 45 47 52 54 |
| xiaomi | `sea` | `thermal-normal.conf` | `NORMAL-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 44 46 48 49 51 | 46 48 50 51 53 |
| xiaomi | `sea` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 40 47.5 49 51 | 43 50.5 52 54 |
| xiaomi | `sea` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 45 48 50 | 48 51 53 |
| xiaomi | `sea` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `sea` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 44 46 48 50 | 48 50 52 54 |
| xiaomi | `sea` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 43 45 47 49 | 47 49 51 53 |
| xiaomi | `sea` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 52 | 54 | 2 | 41 42 43 45 50 52 | 43 44 45 47 52 54 |
| xiaomi | `sea` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 44 46 48 49 51 | 46 48 50 51 53 |
| xiaomi | `sea` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `sea` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-CCC` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `sea` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 51.5 | 4 | 38 41 44 45 47 47.5 | 42 45 48 49 51 51.5 |
| xiaomi | `sea` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 43 45.5 46 48 | 47 49.5 50 52 |
| xiaomi | `selene` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `selene` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `selene` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `selene` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 38 42 45 | 42 46 49 |
| xiaomi | `selene` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 38 42 45 47 | 40 44 47 49 |
| xiaomi | `selene` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `selene` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `selene` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `selene` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 39 41 48 | 43 45 52 |
| xiaomi | `selene` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `selene` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 38 42 45 | 42 46 49 |
| xiaomi | `selene` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 49 | 2 | 38 42 45 47 | 40 44 47 49 |
| xiaomi | `selene` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 41 | 45 | 4 | 33 35 37 41 | 37 39 41 45 |
| xiaomi | `selene` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 33 35 37 41 46 | 36 38 40 44 49 |
| xiaomi | `selene` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 41 | 45 | 4 | 33 35 37 41 | 37 39 41 45 |
| xiaomi | `selene` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 49 | 3 | 33 35 37 41 46 | 36 38 40 44 49 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `shiva` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU1` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU2` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU3` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU5` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `shiva` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `shiva` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 45 | 49 |
| xiaomi | `shiva` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `shiva` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `shiva` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 48 50 | 51 53 |
| xiaomi | `shiva` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `shiva` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 39 41 48 | 43 45 52 |
| xiaomi | `shiva` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 51 | 38 53 |
| xiaomi | `shiva` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `shiva` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 36 38 40 42 44 46 50 51 | 38 40 42 44 46 48 52 53 |
| xiaomi | `shiva` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `shiva` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `sky` | `thermal-camera-global.conf` | `GLOBAL-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-camera-global.conf` | `GLOBAL-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-camera-global.conf` | `GLOBAL-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-camera-global.conf` | `GLOBAL-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-camera-india.conf` | `INDIA-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-camera-india.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-camera-india.conf` | `INDIA-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-camera-india.conf` | `INDIA-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-camera-jp.conf` | `JP-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-camera-jp.conf` | `JP-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-camera-jp.conf` | `JP-CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-camera-jp.conf` | `JP-CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 40 43.5 45 46 | 40 42 44 45 48.5 50 51 |
| xiaomi | `sky` | `thermal-chg-only-global.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-chg-only-global.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-chg-only-india.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-chg-only-india.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-chg-only-jp.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-chg-only-jp.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0-global.conf` | `GLOBAL-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-class0-global.conf` | `GLOBAL-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0-global.conf` | `GLOBAL-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0-india.conf` | `INDIA-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-class0-india.conf` | `INDIA-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0-india.conf` | `INDIA-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0-jp.conf` | `JP-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-class0-jp.conf` | `JP-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0-jp.conf` | `JP-CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-demo-jp.conf` | `JP-DEMO-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-demo-jp.conf` | `JP-DEMO-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-mgame-global.conf` | `GLOBAL-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-hp-mgame-global.conf` | `GLOBAL-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-hp-mgame-india.conf` | `INDIA-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-hp-mgame-india.conf` | `INDIA-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-hp-mgame-jp.conf` | `JP-HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-hp-mgame-jp.conf` | `JP-HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-hp-normal-global.conf` | `GLOBAL-HP-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-normal-global.conf` | `GLOBAL-HP-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-normal-india.conf` | `INDIA-HP-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-normal-india.conf` | `INDIA-HP-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-normal-jp.conf` | `JP-HP-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-normal-jp.conf` | `JP-HP-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-normal.conf` | `HP-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-hp-normal.conf` | `HP-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-mgame-global.conf` | `GLOBAL-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-mgame-global.conf` | `GLOBAL-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-mgame-global.conf` | `GLOBAL-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-mgame-global.conf` | `GLOBAL-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-mgame-india.conf` | `INDIA-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-mgame-india.conf` | `INDIA-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-mgame-india.conf` | `INDIA-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-mgame-india.conf` | `INDIA-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-mgame-jp.conf` | `JP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-mgame-jp.conf` | `JP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-mgame-jp.conf` | `JP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 39 40 41 45 | 42 43 44 45 46 50 |
| xiaomi | `sky` | `thermal-mgame-jp.conf` | `JP-MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 39 40 41 45 | 42 43 44 45 46 50 |
| xiaomi | `sky` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `sky` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `sky` | `thermal-navigation-global.conf` | `GLOBAL-NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-navigation-global.conf` | `GLOBAL-NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-navigation-global.conf` | `GLOBAL-NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-navigation-india.conf` | `INDIA-NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-navigation-india.conf` | `INDIA-NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-navigation-india.conf` | `INDIA-NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-navigation-jp.conf` | `JP-NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-navigation-jp.conf` | `JP-NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-navigation-jp.conf` | `JP-NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-navigation.conf` | `NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-navigation.conf` | `NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-navigation.conf` | `NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal-global.conf` | `GLOBAL-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal-global.conf` | `GLOBAL-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal-india.conf` | `INDIA-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal-india.conf` | `INDIA-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal-jp.conf` | `JP-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal-jp.conf` | `JP-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-phone-global.conf` | `GLOBAL-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-phone-global.conf` | `GLOBAL-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-phone-global.conf` | `GLOBAL-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-phone-india.conf` | `INDIA-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-phone-india.conf` | `INDIA-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-phone-india.conf` | `INDIA-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-phone-jp.conf` | `JP-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-phone-jp.conf` | `JP-PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-phone-jp.conf` | `JP-PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 25 30 40 | 30 35 45 |
| xiaomi | `sky` | `thermal-tgame-global.conf` | `GLOBAL-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-tgame-global.conf` | `GLOBAL-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-tgame-global.conf` | `GLOBAL-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-tgame-global.conf` | `GLOBAL-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-tgame-india.conf` | `INDIA-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-tgame-india.conf` | `INDIA-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-tgame-india.conf` | `INDIA-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-tgame-india.conf` | `INDIA-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 42.5 44 45 | 33 42 45 47.5 49 50 |
| xiaomi | `sky` | `thermal-tgame-jp.conf` | `JP-TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-tgame-jp.conf` | `JP-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-tgame-jp.conf` | `JP-TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 39 40 41 45 | 42 43 44 45 46 50 |
| xiaomi | `sky` | `thermal-tgame-jp.conf` | `JP-TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 38 39 40 41 45 | 42 43 44 45 46 50 |
| xiaomi | `sky` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 48 49 50 | 53 54 55 |
| xiaomi | `sky` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `sky` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 28 37 40 43 44 45 | 33 42 45 48 49 50 |
| xiaomi | `sky` | `thermal-update-global.conf` | `GLOBAL-UPDATE-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-update-global.conf` | `GLOBAL-UPDATE-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-update.conf` | `UPDATE-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-update.conf` | `UPDATE-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video-global.conf` | `GLOBAL-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-video-global.conf` | `GLOBAL-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video-global.conf` | `GLOBAL-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video-india.conf` | `INDIA-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-video-india.conf` | `INDIA-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video-india.conf` | `INDIA-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video-jp.conf` | `JP-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-video-jp.conf` | `JP-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video-jp.conf` | `JP-VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 42 45 46 | 38 40 42 44 45 47 50 51 |
| xiaomi | `sky` | `thermal-videochat-global.conf` | `GLOBAL-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-videochat-global.conf` | `GLOBAL-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-videochat-global.conf` | `GLOBAL-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 45 46 | 38 40 42 44 45 46 50 51 |
| xiaomi | `sky` | `thermal-videochat-global.conf` | `GLOBAL-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 42 46 | 38 40 42 44 45 46 47 51 |
| xiaomi | `sky` | `thermal-videochat-india.conf` | `INDIA-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-videochat-india.conf` | `INDIA-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-videochat-india.conf` | `INDIA-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 45 46 | 38 40 42 44 45 46 50 51 |
| xiaomi | `sky` | `thermal-videochat-india.conf` | `INDIA-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 42 46 | 38 40 42 44 45 46 47 51 |
| xiaomi | `sky` | `thermal-videochat-jp.conf` | `JP-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-videochat-jp.conf` | `JP-VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-videochat-jp.conf` | `JP-VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 45 46 | 38 40 42 44 45 46 50 51 |
| xiaomi | `sky` | `thermal-videochat-jp.conf` | `JP-VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 42 46 | 38 40 42 44 45 46 47 51 |
| xiaomi | `sky` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sky` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 42 43 44 | 47 48 49 |
| xiaomi | `sky` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 45 46 | 38 40 42 44 45 46 50 51 |
| xiaomi | `sky` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 33 35 37 39 40 41 42 46 | 38 40 42 44 45 46 47 51 |
| xiaomi | `spark` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 44 46 48 | 46 48 50 |
| xiaomi | `spark` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 40 42 44 46 47 | 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 47.5 | 51 | 3.5 | 40.5 42.5 44.5 46.5 47.5 | 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 38 46 49 | 39 47 50 |
| xiaomi | `spark` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-class0.conf` | `CLASS0-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 38 40 42 44 46 47 | 42 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 44 46 48 | 46 48 50 |
| xiaomi | `spark` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `spark` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `spark` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 45 47 49 | 46 48 50 |
| xiaomi | `spark` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 40 42 44 46 48 | 41 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 29 | 4 | 25 | 29 |
| xiaomi | `spark` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 43 | 47 | 4 | 39 41 43 | 43 45 47 |
| xiaomi | `spark` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 39 41 43 45 47 | 40 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 39 41 43 45 47 | 40 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 42 44 46 47 | 43 44 46 48 50 51 |
| xiaomi | `spark` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 45 47 49 | 46 48 50 |
| xiaomi | `spark` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 40 42 44 46 48 | 43 45 47 49 51 |
| xiaomi | `spark` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 49 | 50 | 1 | 45 47 49 | 46 48 50 |
| xiaomi | `spark` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 42 44 46 48 | 42 45 47 49 51 |
| xiaomi | `spark` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 42 44 46 48 | 42 45 47 49 51 |
| xiaomi | `spes` | `thermal-4k.conf` | `4K-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 50.5 | 0.5 | 37 43 50 | 37.5 43.5 50.5 |
| xiaomi | `spes` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `spes` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `spes` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 12 | 17 | 5 | 12 | 17 |
| xiaomi | `spes` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `spes` | `thermal-camera.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50.5 | 4.5 | 42 44 46 | 46.5 48.5 50.5 |
| xiaomi | `spes` | `thermal-camera.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 46.5 | 51 | 4.5 | 42.5 44.5 46.5 | 47 49 51 |
| xiaomi | `spes` | `thermal-class0.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50.5 | 4.5 | 40.5 42 43 45 46 | 45 46.5 47.5 49.5 50.5 |
| xiaomi | `spes` | `thermal-class0.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 41 42.5 44 | 45 46 47.5 49 |
| xiaomi | `spes` | `thermal-navigation.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50.5 | 4.5 | 40.5 42 43 45 46 | 45 46.5 47.5 49.5 50.5 |
| xiaomi | `spes` | `thermal-navigation.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 41 42.5 44 | 45 46 47.5 49 |
| xiaomi | `spes` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `spes` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `spes` | `thermal-nolimits.conf` | `NL-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 50.5 | 0.5 | 50 | 50.5 |
| xiaomi | `spes` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50.5 | 4.5 | 40.5 42 43 45 46 | 45 46.5 47.5 49.5 50.5 |
| xiaomi | `spes` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 41 42.5 44 | 45 46 47.5 49 |
| xiaomi | `spes` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `spes` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `spes` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `spes` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 34 | 39 | 5 | 34 | 39 |
| xiaomi | `spes` | `thermal-video.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 50.5 | 4.5 | 40.5 42 43 45 46 | 45 46.5 47.5 49.5 50.5 |
| xiaomi | `spes` | `thermal-video.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 40 41 42.5 44 | 45 46 47.5 49 |
| xiaomi | `spes` | `thermal-videochat.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 36 38.5 42 44 | 41 43.5 47 49 |
| xiaomi | `spes` | `thermal-videochat.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 44.5 | 49.5 | 5 | 37.5 38 41.5 43.5 44.5 | 42.5 43 46.5 48.5 49.5 |
| xiaomi | `spes` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `spes` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `star` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `star` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 45 52 | 46 53 |
| xiaomi | `star` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 45 52 | 46 53 |
| xiaomi | `star` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `star` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 43 45 48 | 20 42 44 48 50 53 |
| xiaomi | `star` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 43 45 48 | 20 42 44 48 50 53 |
| xiaomi | `star` | `thermal-india-normal.conf` | `INDIA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-india-normal.conf` | `INDIA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `star` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-india-normal.conf` | `INDIA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-india-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-k1a-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `star` | `thermal-k1a-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-k1a-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 45 52 | 46 53 |
| xiaomi | `star` | `thermal-k1a-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 45 52 | 46 53 |
| xiaomi | `star` | `thermal-k1a-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-k1a-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `star` | `thermal-k1a-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-k1a-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-k1a-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-k1a-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 43 45 48 | 20 42 44 48 50 53 |
| xiaomi | `star` | `thermal-k1a-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 43 45 48 | 20 42 44 48 50 53 |
| xiaomi | `star` | `thermal-k1a-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `star` | `thermal-k1a-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-k1a-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-k1a-nolimits.conf` | `NL-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `star` | `thermal-k1a-nolimits.conf` | `NL-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `star` | `thermal-k1a-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-k1a-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-k1a-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `star` | `thermal-k1a-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-k1a-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-k1a-per-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-k1a-per-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-per-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 41 42 43 45 48 | 20 42 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-k1a-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 41 42 43 45 48 | 20 42 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-k1a-per-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-per-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-k1a-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-k1a-per-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-per-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-k1a-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-k1a-per-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-per-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-k1a-per-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-k1a-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `star` | `thermal-k1a-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `star` | `thermal-k1a-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-k1a-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `star` | `thermal-k1a-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `star` | `thermal-k1a-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-k1a-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-k1a-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-k1a-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-k1a-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `star` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-nolimits.conf` | `NL-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `star` | `thermal-nolimits.conf` | `NL-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `star` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `star` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-per-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 38 41 43 45 51 | 40 43 45 47 53 |
| xiaomi | `star` | `thermal-per-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-per-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 41 42 43 45 48 | 20 42 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 37 39 41 42 43 45 48 | 20 42 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-per-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-per-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-per-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-per-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 15 39 41 42 43 45 48 | 20 44 46 47 48 50 53 |
| xiaomi | `star` | `thermal-per-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-per-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-per-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `star` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `star` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `star` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `star` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `star` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `star` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `star` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `star` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `star` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-camera.conf` | `CAM-MONITOR-GPU` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 40 41 42 | 45 46 47 |
| xiaomi | `sunstone` | `thermal-camera.conf` | `CAM-SS-SILVER` | `VIRTUAL-SENSOR` | 46 | 47 | 1 | 40 41 42 43.5 46 | 41 42 43 44.5 47 |
| xiaomi | `sunstone` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `sunstone` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sunstone` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sunstone` | `thermal-normal-india.conf` | `NORMAL-IN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `sunstone` | `thermal-normal.conf` | `NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `sunstone` | `thermal-phone.conf` | `PHONE-SS-SILVER` | `VIRTUAL-SENSOR` | 45 | 47 | 2 | 27 42 45 | 29 44 47 |
| xiaomi | `sunstone` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sunstone` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 41 43 45 | 46 48 50 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU1` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU2` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU3` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU5` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `sunstone` | `thermal-youtube.conf` | `YTB-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 43 45 47 | 47 49 51 |
| xiaomi | `surya` | `thermal-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 38 44 51 | 41 47 54 |
| xiaomi | `surya` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `surya` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `surya` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `surya` | `thermal-camera.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `surya` | `thermal-camera.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 52 | 53 |
| xiaomi | `surya` | `thermal-camera.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `surya` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `surya` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `surya` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `surya` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `surya` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `surya` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `surya` | `thermal-phone.conf` | `PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `surya` | `thermal-tgame.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `sweet` | `thermal-4k.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sweet` | `thermal-4k.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `sweet` | `thermal-4k.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 35 37 39 41 43 45 | 38 40 42 44 46 48 |
| xiaomi | `sweet` | `thermal-4k.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 47.5 | 2.5 | 35 37 39 41 43 45 | 37.5 39.5 41.5 43.5 45.5 47.5 |
| xiaomi | `sweet` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sweet` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 42.5 | 47.5 | 5 | 34 36 40 42.5 | 39 41 45 47.5 |
| xiaomi | `sweet` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 42.5 | 47.5 | 5 | 34 36 40 42.5 | 39 41 45 47.5 |
| xiaomi | `sweet` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sweet` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 48 | 0.5 | 35 39 45 47.5 | 35.5 39.5 45.5 48 |
| xiaomi | `sweet` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sweet` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 15 39 40 41 42 43 46.5 | 16.5 40.5 41.5 42.5 43.5 44.5 48 |
| xiaomi | `sweet` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 47.5 | 1 | 15 39 40 41 42 43 46.5 | 16 40 41 42 43 44 47.5 |
| xiaomi | `sweet` | `thermal-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sweet` | `thermal-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `sweet` | `thermal-navigation.conf` | `NAV-SS-CPU0` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 32 34.5 36.5 40 | 37 39.5 41.5 45 |
| xiaomi | `sweet` | `thermal-navigation.conf` | `NAV-SS-CPU6` | `VIRTUAL-SENSOR` | 40 | 45 | 5 | 32 34.5 36.5 40 | 37 39.5 41.5 45 |
| xiaomi | `sweet` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `sweet` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 49 | 54 | 5 | 49 | 54 |
| xiaomi | `sweet` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47.5 | 48 | 0.5 | 38 40 45 47.5 | 38.5 40.5 45.5 48 |
| xiaomi | `sweet` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sweet` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweet` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 30 33.5 44 | 34 37.5 48 |
| xiaomi | `sweet` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 47.5 | 3.5 | 30 33.5 44 | 33.5 37 47.5 |
| xiaomi | `sweet` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `sweet` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46.5 | 48 | 1.5 | 15 39 40 41 42 43 46.5 | 16.5 40.5 41.5 42.5 43.5 44.5 48 |
| xiaomi | `sweet` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 47.5 | 1 | 15 39 40 41 42 43 46.5 | 16 40 41 42 43 44 47.5 |
| xiaomi | `sweet` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `sweet` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweet` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 30 32 34.5 40 43 | 35 37 39.5 45 48 |
| xiaomi | `sweet` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47.5 | 4.5 | 30 32 36.5 40 43 | 34.5 36.5 41 44.5 47.5 |
| xiaomi | `sweet` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `sweet` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 34 36 38 42 44 | 38 40 42 46 48 |
| xiaomi | `sweet` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 44 | 47.5 | 3.5 | 34 36 38 42 44 | 37.5 39.5 41.5 45.5 47.5 |
| xiaomi | `sweet` | `thermal-youtube.conf` | `YTB-SS-CPU0` | `VIRTUAL-SENSOR` | 43 | 48 | 5 | 33 34 37 40 43 | 38 39 42 45 48 |
| xiaomi | `sweet` | `thermal-youtube.conf` | `YTB-SS-CPU6` | `VIRTUAL-SENSOR` | 43 | 47.5 | 4.5 | 33 34 37 40 43 | 37.5 38.5 41.5 44.5 47.5 |
| xiaomi | `sweetin` | `thermal-camera.conf` | `INIDA-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweetin` | `thermal-camera.conf` | `INIDA-CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `sweetin` | `thermal-class0.conf` | `INIDA-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweetin` | `thermal-class0.conf` | `INIDA-CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `sweetin` | `thermal-navigation.conf` | `INIDA-NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweetin` | `thermal-navigation.conf` | `INIDA-NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `sweetin` | `thermal-nolimits.conf` | `INIDA-NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweetin` | `thermal-nolimits.conf` | `INIDA-NL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `sweetin` | `thermal-phone.conf` | `INIDA-PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweetin` | `thermal-phone.conf` | `INIDA-PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `sweetin` | `thermal-video.conf` | `INIDA-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `sweetin` | `thermal-video.conf` | `INIDA-VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 55 | 5 | 50 | 55 |
| xiaomi | `taoyao` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `taoyao` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 41 43 44.5 47 | 39 41 45 47 48.5 51 |
| xiaomi | `taoyao` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 41 43 44.5 47 | 39 41 45 47 48.5 51 |
| xiaomi | `taoyao` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `taoyao` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 42 | 46 |
| xiaomi | `taoyao` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `taoyao` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `taoyao` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `taoyao` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `taoyao` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `taoyao` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `taoyao` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 41 42 43.5 47 | 39 43 45 46 47.5 51 |
| xiaomi | `taoyao` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 41 42 43.5 47 | 39 43 45 46 47.5 51 |
| xiaomi | `taoyao` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `taoyao` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 39 40.2 41 45 47 | 29 43 44.2 45 49 51 |
| xiaomi | `taoyao` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 39 40.2 41 45 47 | 29 43 44.2 45 49 51 |
| xiaomi | `taoyao` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `taoyao` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `taoyao` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `taoyao` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `taoyao` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `taoyao` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `taoyao` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 38.5 41 43 44.5 47 | 39 42.5 45 47 48.5 51 |
| xiaomi | `taoyao` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 38.5 41 43 44.5 47 | 39 42.5 45 47 48.5 51 |
| xiaomi | `taoyao` | `thermal-videochat.conf` | `videochat-MONITOR-CCC` | `VIRTUAL-SENSOR1` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `thor` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `thor` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `thor` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 45 48 | 47 50 |
| xiaomi | `thor` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 45 48 | 47 50 |
| xiaomi | `thor` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 47 48 | 40 42 44 46 50 51 |
| xiaomi | `thor` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `thor` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `thor` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `thor` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 25 35 37 39 41 43 45 48 | 27 37 39 41 43 45 47 50 |
| xiaomi | `thor` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 25 35 37 39 41 43 45 48 | 27 37 39 41 43 45 47 50 |
| xiaomi | `thor` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR1` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `thor` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR1` | 42.5 | 48.5 | 6 | 25 35 37 39 41 42.5 | 31 41 43 45 47 48.5 |
| xiaomi | `thor` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR1` | 42.5 | 48.5 | 6 | 25 35 37 39 41 42.5 | 31 41 43 45 47 48.5 |
| xiaomi | `thor` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `thor` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `thor` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `thor` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `thor` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `thor` | `thermal-nightvideo.conf` | `NIGHTVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-nightvideo.conf` | `NIGHTVIDEO-SS-CPU4` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 37 39 41 43 47 48 | 39 41 43 45 49 50 |
| xiaomi | `thor` | `thermal-nightvideo.conf` | `NIGHTVIDEO-SS-CPU7` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 35 37 39 41 43 45 46 47 48 | 37 39 41 43 45 47 48 49 50 |
| xiaomi | `thor` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `thor` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `thor` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `thor` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `thor` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `thor` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `thor` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `thor` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `thor` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `thor` | `thermal-sptm.conf` | `SPTM-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-sptm.conf` | `SPTM-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-sptm.conf` | `SPTM-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 46 47 48 | 48 49 50 51 |
| xiaomi | `thor` | `thermal-sptm.conf` | `SPTM-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 46 47 48 | 48 49 50 51 |
| xiaomi | `thor` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thor` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thor` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `thor` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR1` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `thor` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 25 35 37 39 41 43 45 48 | 27 37 39 41 43 45 47 50 |
| xiaomi | `thor` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 25 35 37 39 41 43 45 48 | 27 37 39 41 43 45 47 50 |
| xiaomi | `thyme` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-4k.conf` | `4K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `thyme` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `thyme` | `thermal-8k.conf` | `8K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-8k.conf` | `8K-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-8k.conf` | `8K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `thyme` | `thermal-8k.conf` | `8K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 48 | 28 51 |
| xiaomi | `thyme` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 45.5 46 46.5 47 47.5 48 | 42 44 46 48 48.5 49 49.5 50 50.5 51 |
| xiaomi | `thyme` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 45.5 46 46.5 47 48 | 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 38 39 41 43 45 45.5 46 46.5 47 48 | 18 41 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 38 39 41 43 45 46 47 48 | 18 41 42 44 46 48 49 50 51 |
| xiaomi | `thyme` | `thermal-mgame.conf` | `MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `thyme` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 15 46 | 20 51 |
| xiaomi | `thyme` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 38 39 41 43 45 45.5 46 46.5 47 48 | 18 41 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 38 39 41 43 45 46 47 48 | 18 41 42 44 46 48 49 50 51 |
| xiaomi | `thyme` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 38 39 41 43 45 45.5 46 46.5 47 48 | 18 41 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 38 39 41 43 45 46 47 48 | 18 41 42 44 46 48 49 50 51 |
| xiaomi | `thyme` | `thermal-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-per-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 45.5 46 46.5 47 47.5 48 | 42 44 46 48 48.5 49 49.5 50 50.5 51 |
| xiaomi | `thyme` | `thermal-per-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 45.5 46 46.5 47 48 | 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 45 45.5 46 46.5 47 48 | 41 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 45 46 47 48 | 41 42 44 46 48 49 50 51 |
| xiaomi | `thyme` | `thermal-per-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-per-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 45 45.5 46 46.5 47 48 | 41 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 45 46 47 48 | 41 42 44 46 48 49 50 51 |
| xiaomi | `thyme` | `thermal-per-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-per-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 45 45.5 46 46.5 47 48 | 41 42 44 46 48 48.5 49 49.5 50 51 |
| xiaomi | `thyme` | `thermal-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 39 41 43 45 46 47 48 | 41 42 44 46 48 49 50 51 |
| xiaomi | `thyme` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `thyme` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 37 | 43 | 6 | 27 37 | 33 43 |
| xiaomi | `thyme` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 37 | 43 | 6 | 27 37 | 33 43 |
| xiaomi | `thyme` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `thyme` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `tiare` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL` | `xo_therm` | 47 | 52 | 5 | 44 47 | 49 52 |
| xiaomi | `tiare` | `thermal-engine-normal.conf` | `TEMP_STATE_CTL` | `xo_therm` | 55 | 55 | 0 | 44 55 | 49 55 |
| xiaomi | `toco` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `toco` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `toco` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `toco` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `toco` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `toco` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 38 42 45 51 | 41 45 48 54 |
| xiaomi | `toco` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `toco` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `toco` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `toco` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `toco` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `toco` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 36 38 42 45 48 51 | 39 41 45 48 51 54 |
| xiaomi | `toco` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `toco` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `toco` | `thermal-phone.conf` | `PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `toco` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 51 | 54 |
| xiaomi | `tulip` | `thermal-engine-Youtube.conf` | `LCD_MONITOR_VIDEO` | `backlight_therm` | 45 | 50 | 5 | 42 43 44 45 | 47 48 49 50 |
| xiaomi | `tulip` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_STL` | `quiet_therm` | 46 | 51 | 5 | 40 42 44 44.5 45 46 | 45 47 49 49.5 50 51 |
| xiaomi | `tulip` | `thermal-engine-camera.conf` | `CAMCORDER_MONITOR` | `quiet_therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `tulip` | `thermal-engine-camera.conf` | `LCD_MONITOR` | `backlight_therm` | 48 | 53 | 5 | 45 46 47 48 | 50 51 52 53 |
| xiaomi | `tulip` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet_therm` | 46 | 51 | 5 | 40 42 44 44.5 45 46 | 45 47 49 49.5 50 51 |
| xiaomi | `tulip` | `thermal-engine-normal.conf` | `CAMCORDER_MONITOR` | `quiet_therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `tulip` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `backlight_therm` | 48 | 53 | 5 | 45 46 47 48 | 50 51 52 53 |
| xiaomi | `tulip` | `thermal-engine-normal.conf` | `MONITOR-MSM-THERM-HOTPLUG` | `msm_therm` | 51 | 55 | 4 | 45 47 49 51 | 50 52 54 55 |
| xiaomi | `tulip` | `thermal-engine-sgame.conf` | `BATTERY_CHARGING_STL` | `quiet_therm` | 46 | 51 | 5 | 40 42 44 44.5 45 46 | 45 47 49 49.5 50 51 |
| xiaomi | `tulip` | `thermal-engine-sgame.conf` | `CAMCORDER_MONITOR` | `quiet_therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `tulip` | `thermal-engine-sgame.conf` | `LCD_MONITOR` | `backlight_therm` | 48 | 53 | 5 | 45 46 47 48 | 50 51 52 53 |
| xiaomi | `tulip` | `thermal-engine-sgame.conf` | `MONITOR-MSM-THERM-HOTPLUG` | `msm_therm` | 51 | 55 | 4 | 45 47 49 51 | 50 52 54 55 |
| xiaomi | `unicorn` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 44 46 48 | 47 49 51 |
| xiaomi | `unicorn` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `unicorn` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `unicorn` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `unicorn` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `unicorn` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `unicorn` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `unicorn` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `unicorn` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `unicorn` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `unicorn` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `unicorn` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `unicorn` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `unicorn` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `unicorn` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `unicorn` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `unicorn` | `thermal-sptm.conf` | `SPTM-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-sptm.conf` | `SPTM-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 45 | 51 |
| xiaomi | `unicorn` | `thermal-sptm.conf` | `SPTM-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 46 47 48 | 48 49 50 51 |
| xiaomi | `unicorn` | `thermal-sptm.conf` | `SPTM-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 46 47 48 | 48 49 50 51 |
| xiaomi | `unicorn` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `unicorn` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `unicorn` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `unicorn` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `unicorn` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `unicorn` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR1` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `vangogh` | `thermal-4k.conf` | `4K-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `vangogh` | `thermal-4k.conf` | `4k-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `vangogh` | `thermal-4k.conf` | `4k-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `vangogh` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `vangogh` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `vangogh` | `thermal-arvr.conf` | `ARVR-SS-CPU6` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `vangogh` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 11 | 16 | 5 | 11 | 16 |
| xiaomi | `vangogh` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `vangogh` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `vangogh` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `vangogh` | `thermal-chg-only.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `vangogh` | `thermal-nolimits.conf` | `NL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `vangogh` | `thermal-nolimits.conf` | `NL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `vangogh` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `vangogh` | `thermal-normal.conf` | `MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 47 | 1 | 46 | 47 |
| xiaomi | `vangogh` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `vangogh` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `vangogh` | `thermal-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `vangogh` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `vangogh` | `thermal-per-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `vangogh` | `thermal-per-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 51 | 53 |
| xiaomi | `vangogh` | `thermal-per-normal.conf` | `MONITOR-CCC_CTRL` | `VIRTUAL-SENSOR` | 46 | 47 | 1 | 46 | 47 |
| xiaomi | `vangogh` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `vangogh` | `thermal-per-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 41 43 45 47 51 | 44 46 48 50 54 |
| xiaomi | `vangogh` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 25 | 30 | 5 | 25 | 30 |
| xiaomi | `vangogh` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 43 45 48 | 48 50 53 |
| xiaomi | `vangogh` | `thermal-phone.conf` | `PHONE-SS-CPU6-0` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `vangogh` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 33 | 38 | 5 | 33 | 38 |
| xiaomi | `vangogh` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 51 | 54 | 3 | 44 45 47 51 | 47 48 50 54 |
| xiaomi | `vayu` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `vayu` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 20 | 26 | 6 | 20 | 26 |
| xiaomi | `vayu` | `thermal-normal.conf` | `MONITOR-HOTPLUG_CPU1` | `VIRTUAL-SENSOR` | 44 | 50 | 6 | 44 | 50 |
| xiaomi | `vayu` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 51 | 52 | 1 | 45 47 51 | 46 48 52 |
| xiaomi | `vayu` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 51 | 53 | 2 | 45 47 51 | 47 49 53 |
| xiaomi | `vayu` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `vayu` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 50 | 52 | 2 | 50 | 52 |
| xiaomi | `venus` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `venus` | `thermal-8k.conf` | `8K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `venus` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `venus` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `venus` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `venus` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `venus` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `venus` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `venus` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `venus` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `venus` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `venus` | `thermal-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `venus` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `venus` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `venus` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `venus` | `thermal-per-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-per-camera.conf` | `CAMERA-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `venus` | `thermal-per-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `venus` | `thermal-per-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `venus` | `thermal-per-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `venus` | `thermal-per-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-per-class0.conf` | `CLASS0-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-per-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-per-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 41 42 43 45 48 | 18 40 42 44 45 46 48 51 |
| xiaomi | `venus` | `thermal-per-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 41 42 43 45 48 | 18 40 42 44 45 46 48 51 |
| xiaomi | `venus` | `thermal-per-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-per-navigation.conf` | `NAV-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-per-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-per-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `venus` | `thermal-per-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `venus` | `thermal-per-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-per-normal.conf` | `MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-per-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-per-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `venus` | `thermal-per-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 39 41 42 43 45 48 | 18 42 44 45 46 48 51 |
| xiaomi | `venus` | `thermal-per-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-per-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-per-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-per-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `venus` | `thermal-per-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `venus` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-phone.conf` | `PHONE-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `venus` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `venus` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `venus` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `venus` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `venus` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `venus` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `venus` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 15 35 37 39 41 43 45 | 21 41 43 45 47 49 51 |
| xiaomi | `veux` | `thermal-camera.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-camera.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `veux` | `thermal-camera.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 46.5 | 51 | 4.5 | 42.5 44.5 46.5 | 47 49 51 |
| xiaomi | `veux` | `thermal-class0.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-class0.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 36 37 38 39 40 42 47 | 40 41 42 43 44 46 51 |
| xiaomi | `veux` | `thermal-class0.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 36 37 38 39 40 42 | 41 42 43 44 45 47 |
| xiaomi | `veux` | `thermal-extreme.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-extreme.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `veux` | `thermal-extreme.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `veux` | `thermal-high.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-high.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `veux` | `thermal-high.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `veux` | `thermal-mgame.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `veux` | `thermal-mgame.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `veux` | `thermal-nevigation.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-nevigation.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `veux` | `thermal-nevigation.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 45 46 | 40 42 44 46 48 50 51 |
| xiaomi | `veux` | `thermal-nolimits.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-nolimits.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `veux` | `thermal-nolimits.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `veux` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 42 43 44 45 47 | 46 47 48 49 51 |
| xiaomi | `veux` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 42 43 44 45 46 47 | 46 47 48 49 50 51 |
| xiaomi | `veux` | `thermal-phone.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-phone.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 33 35 37 38 40 41 42 | 38 40 42 43 45 46 47 |
| xiaomi | `veux` | `thermal-phone.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 42 | 47 | 5 | 33 35 37 38 40 41 42 | 38 40 42 43 45 46 47 |
| xiaomi | `veux` | `thermal-tgame.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `veux` | `thermal-tgame.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 49 | 51 |
| xiaomi | `veux` | `thermal-video.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-video.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 42 44 45 | 42 44 46 47 49 50 |
| xiaomi | `veux` | `thermal-video.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 37 39 41 42 44 45 | 42 44 46 47 49 50 |
| xiaomi | `veux` | `thermal-youtube.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 54 | 55 | 1 | 48 51 54 | 49 52 55 |
| xiaomi | `veux` | `thermal-youtube.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 44 | 49 | 5 | 35 36 37 38 40 42 44 | 40 41 42 43 45 47 49 |
| xiaomi | `veux` | `thermal-youtube.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 50 | 5 | 34 36 38 40 42 44 45 | 39 41 43 45 47 49 50 |
| xiaomi | `vida` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `vida` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 43 44 | 46 47 48 |
| xiaomi | `vida` | `thermal-camera.conf` | `CAMERA-MONITOR-HOTPLUG_CTRL` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `vida` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `vida` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `vida` | `thermal-class0.conf` | `WEIBO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `vida` | `thermal-class0.conf` | `WEIBO-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 35 37 39 40 42 45 48 50 | 38 40 42 43 45 48 51 53 |
| xiaomi | `vida` | `thermal-class0.conf` | `WEIBO-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 35 37 39 40 42 45 48 50 | 38 40 42 43 45 48 51 53 |
| xiaomi | `vida` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `vida` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 47 49 50 | 51 53 54 |
| xiaomi | `vida` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `vida` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `vida` | `thermal-navigation.conf` | `NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `vida` | `thermal-navigation.conf` | `NAVG-MONITOR-HOTPLUG_CTRL` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `vida` | `thermal-navigation.conf` | `NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 36 37 39 41 42 43 44 45 | 40 41 43 45 46 47 48 49 |
| xiaomi | `vida` | `thermal-navigation.conf` | `NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 36 37 39 41 42 43 44 45 | 40 41 43 45 46 47 48 49 |
| xiaomi | `vida` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `vida` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 42 43 44 45 46 47 48 50 | 45 46 47 48 49 50 51 53 |
| xiaomi | `vida` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 42 43 44 45 46 47 48 50 | 45 46 47 48 49 50 51 53 |
| xiaomi | `vida` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `vida` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 38 41 43 45 47 | 36 42 45 47 49 51 |
| xiaomi | `vida` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 38 41 43 45 47 | 36 42 45 47 49 51 |
| xiaomi | `vida` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `vida` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 47 49 50 | 51 53 54 |
| xiaomi | `vida` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `vida` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `vida` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `vida` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 40 42 45 47 | 39 41 44 46 49 51 |
| xiaomi | `vida` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 40 42 45 47 | 39 41 44 46 49 51 |
| xiaomi | `vida` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `vida` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 43 44 | 46 47 48 |
| xiaomi | `vida` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `vida` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `vida` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `vili` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `vili` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `vili` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `vili` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 39 41 42 43 45 | 45 47 48 49 51 |
| xiaomi | `vili` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 39 41 42 43 45 | 45 47 48 49 51 |
| xiaomi | `vili` | `thermal-india-camera.conf` | `INDIA-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-india-camera.conf` | `INDIA-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 38 41 43 45 48 | 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-india-class0.conf` | `INDIA-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `vili` | `thermal-india-class0.conf` | `INDIA-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 15 37 39 43 45 48 | 18 40 42 46 48 51 |
| xiaomi | `vili` | `thermal-india-huanji.conf` | `INDIA-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `vili` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 39 41 42 43 45 | 45 47 48 49 51 |
| xiaomi | `vili` | `thermal-india-huanji.conf` | `INDIA-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 39 41 42 43 45 | 45 47 48 49 51 |
| xiaomi | `vili` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `vili` | `thermal-india-mgame.conf` | `INDIA-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `vili` | `thermal-india-navigation.conf` | `INDIA-NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-india-navigation.conf` | `INDIA-NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-india-navigation.conf` | `INDIA-NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-india-normal.conf` | `INDIA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-india-normal.conf` | `INDIA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-india-normal.conf` | `INDIA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-india-phone.conf` | `INDIA-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-india-phone.conf` | `INDIA-PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 27 45 | 33 51 |
| xiaomi | `vili` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `vili` | `thermal-india-tgame.conf` | `INDIA-TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `vili` | `thermal-india-video.conf` | `INDIA-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-india-video.conf` | `INDIA-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `vili` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `vili` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 39 41 43 45 48 | 33 42 44 46 48 51 |
| xiaomi | `vili` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 39 41 43 45 48 | 33 42 44 46 48 51 |
| xiaomi | `vili` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 27 48 | 30 51 |
| xiaomi | `vili` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `vili` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `vili` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `vili` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `vili` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 30 38 41 43 45 48 | 33 41 44 46 48 51 |
| xiaomi | `violet` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_CTL` | `quiet-therm` | 42 | 47 | 5 | 36 37 38 40 41 42 | 41 42 43 45 46 47 |
| xiaomi | `violet` | `thermal-engine-camera.conf` | `CPU3_HOTPLUG_MONITOR` | `sdm-therm` | 44 | 49 | 5 | 44 | 49 |
| xiaomi | `violet` | `thermal-engine-camera.conf` | `CPU5_HOTPLUG_MONITOR` | `sdm-therm` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `violet` | `thermal-engine-camera.conf` | `CPU_HOTPLUG_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-camera.conf` | `LCD_MANAGEMENT` | `backlight_therm` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `violet` | `thermal-engine-camera.conf` | `LCD_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-camera.conf` | `QUITE_TEMP_STATE` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL` | `quiet-therm` | 43 | 48 | 5 | 37 38 39 41 42 43 | 42 43 44 46 47 48 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `CPU2_HOTPLUG_MONITOR` | `sdm-therm` | 49 | 54 | 5 | 49 | 54 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `CPU3_HOTPLUG_MONITOR` | `sdm-therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `CPU5_HOTPLUG_MONITOR` | `sdm-therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `CPU_HOTPLUG_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `LCD_MANAGEMENT` | `backlight_therm` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `LCD_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-normal.conf` | `QUITE_TEMP_STATE` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `BATTERY_CHARGING_CTL` | `quiet-therm` | 43 | 48 | 5 | 38 39 40 41 42 43 | 43 44 45 46 47 48 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `CPU2_HOTPLUG_MONITOR` | `sdm-therm` | 52 | 55 | 3 | 52 | 55 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `CPU3_HOTPLUG_MONITOR` | `sdm-therm` | 52 | 55 | 3 | 52 | 55 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `CPU5_HOTPLUG_MONITOR` | `sdm-therm` | 52 | 55 | 3 | 52 | 55 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `CPU_HOTPLUG_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `LCD_MANAGEMENT` | `backlight_therm` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `LCD_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-studio.conf` | `QUITE_TEMP_STATE` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `BATTERY_CHARGING_CTL` | `quiet-therm` | 42 | 47 | 5 | 36 37 38 40 41 42 | 41 42 43 45 46 47 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `CPU2_HOTPLUG_MONITOR` | `sdm-therm` | 49 | 54 | 5 | 49 | 54 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `CPU3_HOTPLUG_MONITOR` | `sdm-therm` | 47 | 52 | 5 | 47 | 52 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `CPU5_HOTPLUG_MONITOR` | `sdm-therm` | 45 | 50 | 5 | 45 | 50 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `CPU_HOTPLUG_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `LCD_MANAGEMENT` | `backlight_therm` | 47 | 52 | 5 | 43 45 47 | 48 50 52 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `LCD_MONITOR` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `violet` | `thermal-engine-tgame.conf` | `QUITE_TEMP_STATE` | `quiet-therm` | 54 | 55 | 1 | 54 | 55 |
| xiaomi | `viva` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `viva` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 43 44 | 46 47 48 |
| xiaomi | `viva` | `thermal-camera.conf` | `CAMERA-MONITOR-HOTPLUG_CTRL` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 50 | 54 |
| xiaomi | `viva` | `thermal-camera.conf` | `CAMERA-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `viva` | `thermal-camera.conf` | `CAMERA-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `viva` | `thermal-class0.conf` | `WEIBO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `viva` | `thermal-class0.conf` | `WEIBO-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 35 37 39 40 42 45 48 50 | 38 40 42 43 45 48 51 53 |
| xiaomi | `viva` | `thermal-class0.conf` | `WEIBO-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 35 37 39 40 42 45 48 50 | 38 40 42 43 45 48 51 53 |
| xiaomi | `viva` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `viva` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 47 49 50 | 51 53 54 |
| xiaomi | `viva` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `viva` | `thermal-mgame.conf` | `MGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `viva` | `thermal-navigation.conf` | `NAVG-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `viva` | `thermal-navigation.conf` | `NAVG-MONITOR-HOTPLUG_CTRL` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `viva` | `thermal-navigation.conf` | `NAVG-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 36 37 39 41 42 43 44 45 | 40 41 43 45 46 47 48 49 |
| xiaomi | `viva` | `thermal-navigation.conf` | `NAVG-SS-CPU6` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 36 37 39 41 42 43 44 45 | 40 41 43 45 46 47 48 49 |
| xiaomi | `viva` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 50 | 53 |
| xiaomi | `viva` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 42 43 44 45 46 47 48 50 | 45 46 47 48 49 50 51 53 |
| xiaomi | `viva` | `thermal-normal.conf` | `SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 42 43 44 45 46 47 48 50 | 45 46 47 48 49 50 51 53 |
| xiaomi | `viva` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `viva` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 38 41 43 45 47 | 36 42 45 47 49 51 |
| xiaomi | `viva` | `thermal-phone.conf` | `PHONE-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 32 38 41 43 45 47 | 36 42 45 47 49 51 |
| xiaomi | `viva` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `viva` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 50 | 54 | 4 | 47 49 50 | 51 53 54 |
| xiaomi | `viva` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `viva` | `thermal-tgame.conf` | `TGAME-SS-CPU6` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 45 48 | 49 52 |
| xiaomi | `viva` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `viva` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 40 42 45 47 | 39 41 44 46 49 51 |
| xiaomi | `viva` | `thermal-video.conf` | `VIDEO-SS-CPU6` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 40 42 45 47 | 39 41 44 46 49 51 |
| xiaomi | `viva` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 44 | 48 |
| xiaomi | `viva` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 42 43 44 | 46 47 48 |
| xiaomi | `viva` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU0` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `viva` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU6` | `VIRTUAL-SENSOR` | 50 | 53 | 3 | 36 37 38 42 44 47 48 50 | 39 40 41 45 47 50 51 53 |
| xiaomi | `viva` | `thermal-youtube.conf` | `YTB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `whyred` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL` | `VIRTUAL-LCDON-CHARGE` | 47 | 52 | 5 | 45 47 | 50 52 |
| xiaomi | `whyred` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL_CPU` | `VIRTUAL-CPU-MAX` | 53 | 58 | 5 | 50 53 | 55 58 |
| xiaomi | `whyred` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_CTL_STANDBY` | `quiet_therm` | 39 | 44 | 5 | 39 | 44 |
| xiaomi | `whyred` | `thermal-engine-normal.conf` | `LCD_MANAGEMENT` | `backlight_therm` | 48 | 53 | 5 | 45 46 47 48 | 50 51 52 53 |
| xiaomi | `whyred` | `thermal-engine-normal.conf` | `MONITOR_QUIET_THERM_HOTPLUG` | `quiet_therm` | 50 | 55 | 5 | 44 47 48 50 | 49 52 53 55 |
| xiaomi | `willow` | `thermal-engine-camera.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-adc` | 44 | 49 | 5 | 37.5 39.5 40 41 42 43 44 | 42.5 44.5 45 46 47 48 49 |
| xiaomi | `willow` | `thermal-engine-camera.conf` | `HIGH_TEMP_STATE_flash` | `quiet-therm-adc` | 42 | 47 | 5 | 42 | 47 |
| xiaomi | `willow` | `thermal-engine-camera.conf` | `MONITOR-CPU-HOTPLUG` | `quiet-therm-adc` | 48 | 53 | 5 | 42 44 48 | 47 49 53 |
| xiaomi | `willow` | `thermal-engine-normal.conf` | `BATTERY_CHARGING_STL` | `quiet-therm-adc` | 44 | 49 | 5 | 37.5 39.5 40 41 42 43 44 | 42.5 44.5 45 46 47 48 49 |
| xiaomi | `willow` | `thermal-engine-normal.conf` | `MONITOR-CPU-HOTPLUG` | `quiet-therm-adc` | 48 | 53 | 5 | 42 44 48 | 47 49 53 |
| xiaomi | `xig04` | `thermal-4k.conf` | `4K-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `xig04` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `xig04` | `thermal-arvr.conf` | `ARVR-SS-CPU0` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 45 | 48 |
| xiaomi | `xig04` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 37 52 | 38 53 |
| xiaomi | `xig04` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR` | 52 | 53 | 1 | 37 52 | 38 53 |
| xiaomi | `xig04` | `thermal-camera.conf` | `CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `xig04` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `xig04` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `xig04` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 25 37 39 41 43 44 45 47 48 | 29 41 43 45 47 48 49 51 52 |
| xiaomi | `xig04` | `thermal-cclassvideo.conf` | `CCLASSVIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 44 | 48 | 4 | 25 37 39 41 43 44 | 29 41 43 45 47 48 |
| xiaomi | `xig04` | `thermal-cgame.conf` | `CGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `xig04` | `thermal-cgame.conf` | `CGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 15 45 50 | 16 46 51 |
| xiaomi | `xig04` | `thermal-cgame.conf` | `CGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 19 | 4 | 15 | 19 |
| xiaomi | `xig04` | `thermal-cgame.conf` | `CGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 15 43 46 | 17 45 48 |
| xiaomi | `xig04` | `thermal-cgame.conf` | `CGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `xig04` | `thermal-cgame.conf` | `CGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 46 | 19 50 |
| xiaomi | `xig04` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 33 37 39 41 43 44 45 46 47 | 29 37 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 31 37 39 41 43 44 45 46 47 | 29 35 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-demo.conf` | `DEMO-KDDI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-demo.conf` | `DEMO-KDDI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-demo.conf` | `DEMO-KDDI-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 33 37 39 41 43 44 45 46 47 | 29 37 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-demo.conf` | `DEMO-KDDI-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 25 37 39 41 43 44 45 46 | 29 41 43 45 47 48 49 50 |
| xiaomi | `xig04` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `xig04` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-CCC` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `xig04` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 44 46 | 45 46 48 |
| xiaomi | `xig04` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `xig04` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `xig04` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 47 | 51 |
| xiaomi | `xig04` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-CCC` | `VIRTUAL-SENSOR` | 47 | 50 | 3 | 47 | 50 |
| xiaomi | `xig04` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 35 47 | 36 48 |
| xiaomi | `xig04` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 33 37 39 41 43 44 45 46 47 | 29 37 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `xig04` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `xig04` | `thermal-mgame.conf` | `MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 43 44 46 | 45 46 48 |
| xiaomi | `xig04` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `xig04` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 36 42 43.6 44.2 44.8 46 | 40 46 47.6 48.2 48.8 50 |
| xiaomi | `xig04` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `xig04` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `xig04` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `xig04` | `thermal-nolimits.conf` | `NOLIMITS-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 48 | 52 |
| xiaomi | `xig04` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 33 37 39 41 43 44 45 46 47 | 29 37 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 41 43 44 45 46 47 | 29 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-per-camera.conf` | `PER-CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 41 43 45 | 45 47 49 |
| xiaomi | `xig04` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `xig04` | `thermal-per-camera.conf` | `PER-CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 53 | 4 | 36 38 40 41 42 43 45 48 49 | 40 42 44 45 46 47 49 52 53 |
| xiaomi | `xig04` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `xig04` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `xig04` | `thermal-per-huanji.conf` | `PER-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-per-huanji.conf` | `PER-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `xig04` | `thermal-per-huanji.conf` | `PER-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 46 | 4 | 15 39 41 42 | 19 43 45 46 |
| xiaomi | `xig04` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `xig04` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `xig04` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 50 | 4 | 15 37 39 41 43 44 45 46 | 19 41 43 45 47 48 49 50 |
| xiaomi | `xig04` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `xig04` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 35 39 41 43 44 45 46 47 48 | 39 43 45 47 48 49 50 51 52 |
| xiaomi | `xig04` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43 44 45 46 47 | 39 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43 44 45 46 47 | 39 41 43 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 50 | 51 | 1 | 50 | 51 |
| xiaomi | `xig04` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 27 45 48 | 31 49 52 |
| xiaomi | `xig04` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 27 45 48 | 31 49 52 |
| xiaomi | `xig04` | `thermal-tgame.conf` | `TGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `xig04` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `xig04` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 31 35 37 41 43 44 45 46 47 | 19 35 39 41 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 15 31 35 37 41 43 44 45 46 47 | 19 35 39 41 45 47 48 49 50 51 |
| xiaomi | `xig04` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 33 36 39 41 43 44 45 | 29 37 40 43 45 47 48 49 |
| xiaomi | `xig04` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 49 | 4 | 25 33 36 39 41 43 44 45 | 29 37 40 43 45 47 48 49 |
| xiaomi | `xig04` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `xig04` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 15 35 45 48 | 19 39 49 52 |
| xiaomi | `xig04` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `xig04` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 52 | 4 | 44 45 45.7 46.5 47.2 48 | 48 49 49.7 50.5 51.2 52 |
| xiaomi | `yudi` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `yudi` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `yudi` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `yudi` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `yudi` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `yudi` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 47 48 | 42 44 46 50 51 |
| xiaomi | `yudi` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 47 48 | 42 44 46 47 48 49 50 51 |
| xiaomi | `yudi` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `yudi` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `yudi` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 47 48 | 42 44 46 47 48 49 50 51 |
| xiaomi | `yudi` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 48 | 42 44 46 47 48 51 |
| xiaomi | `yudi` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `yudi` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `yudi` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `yudi` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `yudi` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `yudi` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `yudi` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `yudi` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `yudi` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 47 48 | 42 44 46 47 48 49 50 51 |
| xiaomi | `yudi` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 45 46 47 48 | 42 44 46 48 49 50 51 |
| xiaomi | `yudi` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `yudi` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `yudi` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `yudi` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `yudi` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 41 43 44 45 46 47 48 | 42 44 46 47 48 49 50 51 |
| xiaomi | `yudi` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 41 43 44 45 47 | 43 45 47 48 49 51 |
| xiaomi | `yudi` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `yudi` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 45 47 48 | 38 40 42 44 46 48 50 51 |
| xiaomi | `yudi` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `yudi` | `thermal-yuanshen.conf` | `YUANSHEN-MONITOR-GPU` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `yudi` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `yudi` | `thermal-yuanshen.conf` | `YUANSHEN-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `zeus` | `thermal-abnormal.conf` | `AB-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-abnormal.conf` | `AB-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-abnormal.conf` | `AB-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-abnormal.conf` | `AB-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-abnormal.conf` | `AB-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-arvr.conf` | `ARVR-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-arvr.conf` | `ARVR-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 44 46 48 | 47 49 51 |
| xiaomi | `zeus` | `thermal-arvr.conf` | `ARVR-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `zeus` | `thermal-arvr.conf` | `ARVR-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 45 48 | 48 51 |
| xiaomi | `zeus` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `zeus` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `zeus` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 25 46 | 27 48 |
| xiaomi | `zeus` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `zeus` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 42 44 46 | 47 49 51 |
| xiaomi | `zeus` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `zeus` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `zeus` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `zeus` | `thermal-iec-chg-only.conf` | `IEC-CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `zeus` | `thermal-iec-chg-only.conf` | `IEC-CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 46 47 48 | 28 38 40 42 44 46 48 49 50 51 |
| xiaomi | `zeus` | `thermal-iec-class0.conf` | `IEC-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-class0.conf` | `IEC-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-class0.conf` | `IEC-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-class0.conf` | `IEC-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-class0.conf` | `IEC-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 37 39 41 43 45 48 | 28 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-huanji.conf` | `IEC-HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-huanji.conf` | `IEC-HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-huanji.conf` | `IEC-HUANJI-SS-CPU0` | `VIRTUAL-SENSOR0` | 42.5 | 48 | 5.5 | 25 42.5 | 30.5 48 |
| xiaomi | `zeus` | `thermal-iec-huanji.conf` | `IEC-HUANJI-SS-CPU4` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `zeus` | `thermal-iec-huanji.conf` | `IEC-HUANJI-SS-CPU7` | `VIRTUAL-SENSOR0` | 42.5 | 48.5 | 6 | 15 30 35 37 39 40 41 41.5 42.5 | 21 36 41 43 45 46 47 47.5 48.5 |
| xiaomi | `zeus` | `thermal-iec-mgame.conf` | `IEC-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-mgame.conf` | `IEC-MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zeus` | `thermal-iec-mgame.conf` | `IEC-MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `zeus` | `thermal-iec-mgame.conf` | `IEC-MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `zeus` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-iec-navigation.conf` | `IEC-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-iec-normal.conf` | `IEC-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-normal.conf` | `IEC-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-normal.conf` | `IEC-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-normal.conf` | `IEC-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-iec-normal.conf` | `IEC-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-per-class0.conf` | `IEC-PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-iec-per-navigation.conf` | `IEC-PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zeus` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-iec-per-normal.conf` | `IEC-PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 48 | 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-per-video.conf` | `IEC-PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 48 | 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-phone.conf` | `IEC-PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-phone.conf` | `IEC-PHONE-SS-CPU0` | `VIRTUAL-SENSOR0` | 30 | 36 | 6 | 30 | 36 |
| xiaomi | `zeus` | `thermal-iec-phone.conf` | `IEC-PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `zeus` | `thermal-iec-phone.conf` | `IEC-PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `zeus` | `thermal-iec-tgame.conf` | `IEC-TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-tgame.conf` | `IEC-TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `zeus` | `thermal-iec-tgame.conf` | `IEC-TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `zeus` | `thermal-iec-video.conf` | `IEC-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-video.conf` | `IEC-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-iec-video.conf` | `IEC-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-iec-video.conf` | `IEC-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-video.conf` | `IEC-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-iec-videochat.conf` | `IEC-VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-iec-videochat.conf` | `IEC-VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR1` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `zeus` | `thermal-iec-videochat.conf` | `IEC-VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR1` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `zeus` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR0` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zeus` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `zeus` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 46 | 51 | 5 | 46 | 51 |
| xiaomi | `zeus` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 37 39 41 43 45 48 | 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 37 39 41 43 45 | 31 41 43 45 47 49 51 |
| xiaomi | `zeus` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zeus` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `zeus` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 48 | 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 35 37 39 41 43 45 48 | 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR0` | 30 | 36 | 6 | 30 | 36 |
| xiaomi | `zeus` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `zeus` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR0` | 41 | 47 | 6 | 25 39 41 | 31 45 47 |
| xiaomi | `zeus` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `zeus` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 48 | 51 |
| xiaomi | `zeus` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR0` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR0` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zeus` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR0` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `zeus` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR0` | 48 | 51 | 3 | 25 35 37 39 41 43 45 48 | 28 38 40 42 44 46 48 51 |
| xiaomi | `zeus` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `zeus` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR1` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `zeus` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR1` | 45 | 48 | 3 | 25 35 37 39 41 43 45 | 28 38 40 42 44 46 48 |
| xiaomi | `zijin` | `thermal-chg-only.conf` | `CHG-SS-CPU4` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 39 41 42 43.5 49 | 41 43 44 45.5 51 |
| xiaomi | `zijin` | `thermal-chg-only.conf` | `CHG-SS-CPU7` | `VIRTUAL-SENSOR` | 49 | 51 | 2 | 39 41 42 43.5 49 | 41 43 44 45.5 51 |
| xiaomi | `zijin` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `zijin` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 41 43 44.5 47 | 39 41 45 47 48.5 51 |
| xiaomi | `zijin` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 41 43 44.5 47 | 39 41 45 47 48.5 51 |
| xiaomi | `zijin` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `zijin` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `zijin` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 39 40 41 42 | 41 45 46 47 48 |
| xiaomi | `zijin` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zijin` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `zijin` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `zijin` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `zijin` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 41 42 43.5 47 | 39 43 45 46 47.5 51 |
| xiaomi | `zijin` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 39 41 42 43.5 47 | 39 43 45 46 47.5 51 |
| xiaomi | `zijin` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `zijin` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40.2 41 45 47 | 43 44.2 45 49 51 |
| xiaomi | `zijin` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40.2 41 45 47 | 43 44.2 45 49 51 |
| xiaomi | `zijin` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `zijin` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `zijin` | `thermal-tgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zijin` | `thermal-tgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `zijin` | `thermal-tgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 38.5 42.5 43.7 44.9 46 | 43.5 47.5 48.7 49.9 51 |
| xiaomi | `zijin` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `zijin` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 38.5 41 43 44.5 47 | 39 42.5 45 47 48.5 51 |
| xiaomi | `zijin` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 38.5 41 43 44.5 47 | 39 42.5 45 47 48.5 51 |
| xiaomi | `zijin` | `thermal-videochat.conf` | `videochat-MONITOR-CCC` | `VIRTUAL-SENSOR2` | 48 | 53 | 5 | 48 | 53 |
| xiaomi | `zijin` | `thermal-youtube.conf` | `YTB-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `zijin` | `thermal-youtube.conf` | `YTB-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43.5 47 | 39 41 43 45 47.5 51 |
| xiaomi | `zijin` | `thermal-youtube.conf` | `YTB-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43.5 47 | 39 41 43 45 47.5 51 |
| xiaomi | `ziyi` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `ziyi` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 40.2 41 45 47 | 29 41 43 44.2 45 49 51 |
| xiaomi | `ziyi` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 40.2 41 45 47 | 29 41 43 44.2 45 49 51 |
| xiaomi | `ziyi` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-class0.conf` | `CLASS0-SS-CPU0` | `VIRTUAL-SENSOR` | 39 | 45 | 6 | 25 39 | 31 45 |
| xiaomi | `ziyi` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ziyi` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `ziyi` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ziyi` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ziyi` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `ziyi` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `ziyi` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ziyi` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `ziyi` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 40.2 41 45 47 | 29 41 43 44.2 45 49 51 |
| xiaomi | `ziyi` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 40.2 41 45 47 | 29 41 43 44.2 45 49 51 |
| xiaomi | `ziyi` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ziyi` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 25 42 | 31 48 |
| xiaomi | `ziyi` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 25 30 32 35 40 42 | 31 36 38 41 46 48 |
| xiaomi | `ziyi` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 25 30 32 38 40 42 | 31 36 38 44 46 48 |
| xiaomi | `ziyi` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ziyi` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ziyi` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `ziyi` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `ziyi` | `thermal-navigation.conf` | `NAV-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-navigation.conf` | `NAV-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ziyi` | `thermal-navigation.conf` | `NAV-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-navigation.conf` | `NAV-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ziyi` | `thermal-normal.conf` | `SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `ziyi` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 40.2 41 45 47 | 29 41 43 44.2 45 49 51 |
| xiaomi | `ziyi` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 37 39 40.2 41 45 47 | 29 41 43 44.2 45 49 51 |
| xiaomi | `ziyi` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-phone.conf` | `PHONE-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `ziyi` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `ziyi` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 27 32 42 | 33 38 48 |
| xiaomi | `ziyi` | `thermal-tgame.conf` | `TGAME-MONITOR-GPU` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ziyi` | `thermal-tgame.conf` | `TGAME-SS-CPU0` | `VIRTUAL-SENSOR` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `ziyi` | `thermal-tgame.conf` | `TGAME-SS-CPU4` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `ziyi` | `thermal-tgame.conf` | `TGAME-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 43 46 | 48 51 |
| xiaomi | `ziyi` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-video.conf` | `VIDEO-MONITOR-CCC` | `VIRTUAL-SENSOR` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ziyi` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 48 | 3 | 41 43 45 | 44 46 48 |
| xiaomi | `ziyi` | `thermal-video.conf` | `VIDEO-SS-CPU0` | `VIRTUAL-SENSOR` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `ziyi` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 35 37 39 41 43 45 47 | 29 39 41 43 45 47 49 51 |
| xiaomi | `ziyi` | `thermal-videochat.conf` | `videochat-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR1` | 47 | 48 | 1 | 47 | 48 |
| xiaomi | `ziyi` | `thermal-videochat.conf` | `videochat-MONITOR-CCC` | `VIRTUAL-SENSOR1` | 48 | 50 | 2 | 48 | 50 |
| xiaomi | `ziyi` | `thermal-videochat.conf` | `videochat-SS-CPU0` | `VIRTUAL-SENSOR1` | 25 | 31 | 6 | 25 | 31 |
| xiaomi | `ziyi` | `thermal-videochat.conf` | `videochat-SS-CPU4` | `VIRTUAL-SENSOR1` | 46 | 48 | 2 | 35 36.5 38 40 42 46 | 37 38.5 40 42 44 48 |
| xiaomi | `ziyi` | `thermal-videochat.conf` | `videochat-SS-CPU7` | `VIRTUAL-SENSOR1` | 46 | 48 | 2 | 35 36.5 38 40 42 46 | 37 38.5 40 42 44 48 |
| xiaomi | `zizhan` | `thermal-4k-unfold.conf` | `4K-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zizhan` | `thermal-4k-unfold.conf` | `4K-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 35 37 39 43 47 48 | 38 40 42 46 50 51 |
| xiaomi | `zizhan` | `thermal-4k-unfold.conf` | `4K-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `zizhan` | `thermal-4k.conf` | `4K-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zizhan` | `thermal-4k.conf` | `4K-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `zizhan` | `thermal-4k.conf` | `4K-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `zizhan` | `thermal-abnormal-unfold.conf` | `ABNORMAL-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-abnormal-unfold.conf` | `ABNORMAL-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-abnormal-unfold.conf` | `ABNORMAL-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-abnormal-unfold.conf` | `ABNORMAL-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-abnormal.conf` | `ABNORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-abnormal.conf` | `ABNORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-abnormal.conf` | `ABNORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 10 37 39 41 43 45 47 48 | 13 40 42 44 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-abnormal.conf` | `ABNORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 10 37 39 41 43 45 47 | 14 41 43 45 47 49 51 |
| xiaomi | `zizhan` | `thermal-camera-unfold.conf` | `CAMERA-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-camera-unfold.conf` | `CAMERA-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `zizhan` | `thermal-camera-unfold.conf` | `CAMERA-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-camera.conf` | `CAMERA-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-camera.conf` | `CAMERA-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `zizhan` | `thermal-camera.conf` | `CAMERA-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `zizhan` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-chg-only.conf` | `CHG-ONLY-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 10 30 35 37 39 41 42 43 44 45 | 16 36 41 43 45 47 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-class0-unfold.conf` | `CLASS0-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-class0-unfold.conf` | `CLASS0-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-class0-unfold.conf` | `CLASS0-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-class0-unfold.conf` | `CLASS0-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 37 39 41 43 44 45 46 47 48 50 | 26 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-class0.conf` | `CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-class0.conf` | `CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-class0.conf` | `CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 10 37 39 41 43 45 47 48 | 13 40 42 44 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-class0.conf` | `CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 10 37 39 41 43 45 47 | 14 41 43 45 47 49 51 |
| xiaomi | `zizhan` | `thermal-dolbyvision-unfold.conf` | `DOLBYVISION-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-dolbyvision-unfold.conf` | `DOLBYVISION-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-dolbyvision-unfold.conf` | `DOLBYVISION-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-dolbyvision-unfold.conf` | `DOLBYVISION-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 47 | 51 | 4 | 10 35 37 39 40 43 45 47 | 14 39 41 43 44 47 49 51 |
| xiaomi | `zizhan` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-dolbyvision.conf` | `DOLBYVISION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-dolbyvision.conf` | `DOLBYVISION-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 10 35 37 39 40 43 45 47 | 14 39 41 43 44 47 49 51 |
| xiaomi | `zizhan` | `thermal-hp-mgame-unfold.conf` | `HP-MGAME-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `zizhan` | `thermal-hp-mgame-unfold.conf` | `HP-MGAME-UNFOLD-SS-CPU0` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-hp-mgame-unfold.conf` | `HP-MGAME-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-hp-mgame-unfold.conf` | `HP-MGAME-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-hp-mgame.conf` | `HP-MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-GAME` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `zizhan` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU0` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU4` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-hp-mgame.conf` | `HP-MGAME-SS-CPU7` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-hp-normal-unfold.conf` | `HP-NORMAL-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-hp-normal-unfold.conf` | `HP-NORMAL-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `zizhan` | `thermal-hp-normal-unfold.conf` | `HP-NORMAL-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 35 37 39 41 43 45 46 47 48 | 38 40 42 44 46 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-hp-normal.conf` | `HP-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 43 47 48 | 38 40 42 43 46 50 51 |
| xiaomi | `zizhan` | `thermal-hp-normal.conf` | `HP-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 41 43 47 48 | 38 40 42 44 46 50 51 |
| xiaomi | `zizhan` | `thermal-huanji-unfold.conf` | `HUANJI-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-huanji-unfold.conf` | `HUANJI-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 42 | 48 | 6 | 35 37 39 42 | 41 43 45 48 |
| xiaomi | `zizhan` | `thermal-huanji-unfold.conf` | `HUANJI-UNFOLD-SS-CPU0` | `VIRTUAL-SENSOR-UNFOLD` | 42.5 | 48 | 5.5 | 25 35 37 39 40 42.5 | 30.5 40.5 42.5 44.5 45.5 48 |
| xiaomi | `zizhan` | `thermal-huanji-unfold.conf` | `HUANJI-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `zizhan` | `thermal-huanji-unfold.conf` | `HUANJI-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `zizhan` | `thermal-huanji.conf` | `HUANJI-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-huanji.conf` | `HUANJI-MONITOR-GPU` | `VIRTUAL-SENSOR` | 42 | 48 | 6 | 35 37 39 42 | 41 43 45 48 |
| xiaomi | `zizhan` | `thermal-huanji.conf` | `HUANJI-SS-CPU0` | `VIRTUAL-SENSOR` | 42.5 | 48 | 5.5 | 25 35 37 39 40 42.5 | 30.5 40.5 42.5 44.5 45.5 48 |
| xiaomi | `zizhan` | `thermal-huanji.conf` | `HUANJI-SS-CPU4` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `zizhan` | `thermal-huanji.conf` | `HUANJI-SS-CPU7` | `VIRTUAL-SENSOR` | 42.5 | 48.5 | 6 | 25 30 32 35 39 40 42.5 | 31 36 38 41 45 46 48.5 |
| xiaomi | `zizhan` | `thermal-l18a-normal-unfold.conf` | `L18A-NORMAL-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-l18a-normal-unfold.conf` | `L18A-NORMAL-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-l18a-normal-unfold.conf` | `L18A-NORMAL-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-l18a-normal-unfold.conf` | `L18A-NORMAL-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-l18a-normal.conf` | `L18A-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-l18a-normal.conf` | `L18A-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-l18a-normal.conf` | `L18A-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-l18a-normal.conf` | `L18A-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 39 40 41 42 45 47 | 29 43 44 45 46 49 51 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal-unfold.conf` | `L18A-PER-NORMAL-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal-unfold.conf` | `L18A-PER-NORMAL-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal-unfold.conf` | `L18A-PER-NORMAL-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal-unfold.conf` | `L18A-PER-NORMAL-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal.conf` | `L18A-PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal.conf` | `L18A-PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal.conf` | `L18A-PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-l18a-per-normal.conf` | `L18A-PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 41 42 45 47 | 43 44 45 46 49 51 |
| xiaomi | `zizhan` | `thermal-mgame-unfold.conf` | `MGAME-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `zizhan` | `thermal-mgame-unfold.conf` | `MGAME-UNFOLD-SS-CPU0` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-mgame-unfold.conf` | `MGAME-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-mgame-unfold.conf` | `MGAME-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-GAME-UNFOLD` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-mgame.conf` | `MGAME-MONITOR-GPU` | `VIRTUAL-SENSOR-GAME` | 46 | 50 | 4 | 46 | 50 |
| xiaomi | `zizhan` | `thermal-mgame.conf` | `MGAME-SS-CPU0` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-mgame.conf` | `MGAME-SS-CPU4` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-mgame.conf` | `MGAME-SS-CPU7` | `VIRTUAL-SENSOR-GAME` | 46 | 48 | 2 | 46 | 48 |
| xiaomi | `zizhan` | `thermal-navigation-unfold.conf` | `NAVIGATION-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-navigation-unfold.conf` | `NAVIGATION-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-navigation-unfold.conf` | `NAVIGATION-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 47 | 51 | 4 | 35 37 39 41 43 44 45 46 47 | 39 41 43 45 47 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-navigation-unfold.conf` | `NAVIGATION-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-navigation.conf` | `NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 41 43 44 45 46 47 | 39 41 43 45 47 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-navigation.conf` | `NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 35 37 39 41 43 44 45 46 | 40 42 44 46 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-normal-unfold.conf` | `NORMAL-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-normal-unfold.conf` | `NORMAL-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-normal-unfold.conf` | `NORMAL-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-normal-unfold.conf` | `NORMAL-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 39 41 43 44 45 46 47 48 50 | 26 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-normal.conf` | `MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-normal.conf` | `MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-normal.conf` | `SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 25 39 40 42 45 46 47 48 | 28 42 43 45 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-normal.conf` | `SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 25 39 40 41 42 45 47 | 29 43 44 45 46 49 51 |
| xiaomi | `zizhan` | `thermal-per-abnormal-unfold.conf` | `PER-ABNORMAL-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-abnormal-unfold.conf` | `PER-ABNORMAL-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-per-abnormal-unfold.conf` | `PER-ABNORMAL-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-abnormal-unfold.conf` | `PER-ABNORMAL-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-abnormal.conf` | `PER-ABNORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-abnormal.conf` | `PER-ABNORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-per-abnormal.conf` | `PER-ABNORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-per-abnormal.conf` | `PER-ABNORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `zizhan` | `thermal-per-class0-unfold.conf` | `PER-CLASS0-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-class0-unfold.conf` | `PER-CLASS0-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-per-class0-unfold.conf` | `PER-CLASS0-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-class0-unfold.conf` | `PER-CLASS0-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 37 39 41 43 44 45 46 47 48 50 | 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-class0.conf` | `PER-CLASS0-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 41 43 45 47 48 | 40 42 44 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-per-class0.conf` | `PER-CLASS0-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 37 39 41 43 45 47 | 41 43 45 47 49 51 |
| xiaomi | `zizhan` | `thermal-per-navigation-unfold.conf` | `PER-NAVIGATION-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-navigation-unfold.conf` | `PER-NAVIGATION-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-per-navigation-unfold.conf` | `PER-NAVIGATION-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 47 | 51 | 4 | 37 39 40 41 43 44 45 46 47 | 41 43 44 45 47 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-per-navigation-unfold.conf` | `PER-NAVIGATION-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 46 | 51 | 5 | 37 39 40 41 43 44 45 46 | 42 44 45 46 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-navigation.conf` | `PER-NAVIGATION-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 37 39 40 41 43 44 45 46 47 48 | 40 42 43 44 46 47 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-per-navigation.conf` | `PER-NAVIGATION-SS-CPU7` | `VIRTUAL-SENSOR` | 46 | 51 | 5 | 37 39 40 41 43 44 45 46 | 42 44 45 46 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-per-normal-unfold.conf` | `PER-NORMAL-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-normal-unfold.conf` | `PER-NORMAL-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zizhan` | `thermal-per-normal-unfold.conf` | `PER-NORMAL-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-normal-unfold.conf` | `PER-NORMAL-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 39 41 43 44 45 46 47 48 50 | 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-normal.conf` | `PER-NORMAL-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 35 45 | 31 41 51 |
| xiaomi | `zizhan` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 39 40 42 45 46 47 48 | 42 43 45 48 49 50 51 |
| xiaomi | `zizhan` | `thermal-per-normal.conf` | `PER-NORMAL-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 39 40 41 42 45 47 | 43 44 45 46 49 51 |
| xiaomi | `zizhan` | `thermal-per-video-unfold.conf` | `PER-VIDEO-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-video-unfold.conf` | `PER-VIDEO-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-per-video-unfold.conf` | `PER-VIDEO-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-video-unfold.conf` | `PER-VIDEO-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-video.conf` | `PER-VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-per-video.conf` | `PER-VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 40 43 45 47 | 39 41 43 44 47 49 51 |
| xiaomi | `zizhan` | `thermal-per-youtube-unfold.conf` | `PER-YOUTUBE-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-youtube-unfold.conf` | `PER-YOUTUBE-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-per-youtube-unfold.conf` | `PER-YOUTUBE-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-youtube-unfold.conf` | `PER-YOUTUBE-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 35 37 39 41 43 44 45 46 47 48 50 | 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-per-youtube.conf` | `PER-YOUTUBE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-per-youtube.conf` | `PER-YOUTUBE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 35 39 42 45 | 41 45 48 51 |
| xiaomi | `zizhan` | `thermal-per-youtube.conf` | `PER-YOUTUBE-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 35 37 39 40 43 45 47 48 | 38 40 42 43 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-per-youtube.conf` | `PER-YOUTUBE-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 35 37 39 40 43 45 47 | 39 41 43 44 47 49 51 |
| xiaomi | `zizhan` | `thermal-phone-unfold.conf` | `PHONE-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-phone-unfold.conf` | `PHONE-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-phone-unfold.conf` | `PHONE-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `zizhan` | `thermal-phone-unfold.conf` | `PHONE-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `zizhan` | `thermal-phone.conf` | `PHONE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-phone.conf` | `PHONE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-phone.conf` | `PHONE-SS-CPU4` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `zizhan` | `thermal-phone.conf` | `PHONE-SS-CPU7` | `VIRTUAL-SENSOR` | 45 | 51 | 6 | 25 45 | 31 51 |
| xiaomi | `zizhan` | `thermal-video-unfold.conf` | `VIDEO-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-video-unfold.conf` | `VIDEO-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-video-unfold.conf` | `VIDEO-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-video-unfold.conf` | `VIDEO-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-video.conf` | `VIDEO-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-video.conf` | `VIDEO-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-video.conf` | `VIDEO-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-video.conf` | `VIDEO-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 10 35 37 39 40 43 45 47 | 14 39 41 43 44 47 49 51 |
| xiaomi | `zizhan` | `thermal-videochat-unfold.conf` | `VIDEOCHAT-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-videochat-unfold.conf` | `VIDEOCHAT-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-videochat-unfold.conf` | `VIDEOCHAT-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-videochat-unfold.conf` | `VIDEOCHAT-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 47 | 51 | 4 | 10 30 35 37 39 41 43 45 47 | 14 34 39 41 43 45 47 49 51 |
| xiaomi | `zizhan` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-videochat.conf` | `VIDEOCHAT-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 10 30 35 37 39 41 43 45 47 48 | 13 33 38 40 42 44 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-videochat.conf` | `VIDEOCHAT-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 10 30 35 37 39 41 43 45 47 | 14 34 39 41 43 45 47 49 51 |
| xiaomi | `zizhan` | `thermal-youtube-unfold.conf` | `YOUTUBE-UNFOLD-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR-UNFOLD` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-youtube-unfold.conf` | `YOUTUBE-UNFOLD-MONITOR-GPU` | `VIRTUAL-SENSOR-UNFOLD` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-youtube-unfold.conf` | `YOUTUBE-UNFOLD-SS-CPU4` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-youtube-unfold.conf` | `YOUTUBE-UNFOLD-SS-CPU7` | `VIRTUAL-SENSOR-UNFOLD` | 50 | 51 | 1 | 25 35 37 39 41 43 44 45 46 47 48 50 | 26 36 38 40 42 44 45 46 47 48 49 51 |
| xiaomi | `zizhan` | `thermal-youtube.conf` | `YOUTUBE-MONITOR-BOOST_LIMIT` | `VIRTUAL-SENSOR` | 48 | 49 | 1 | 48 | 49 |
| xiaomi | `zizhan` | `thermal-youtube.conf` | `YOUTUBE-MONITOR-GPU` | `VIRTUAL-SENSOR` | 15 | 21 | 6 | 15 | 21 |
| xiaomi | `zizhan` | `thermal-youtube.conf` | `YOUTUBE-SS-CPU4` | `VIRTUAL-SENSOR` | 48 | 51 | 3 | 10 35 37 39 40 43 45 47 48 | 13 38 40 42 43 46 48 50 51 |
| xiaomi | `zizhan` | `thermal-youtube.conf` | `YOUTUBE-SS-CPU7` | `VIRTUAL-SENSOR` | 47 | 51 | 4 | 10 35 37 39 40 43 45 47 | 14 39 41 43 44 47 49 51 |
