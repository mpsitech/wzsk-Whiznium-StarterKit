<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="11">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col align="end">
					<v-btn-toggle v-model="contapp.ButClaimOn">
						<v-btn
							fab
							small
							light
							color="primary"
							v-on:click="handleButClick('ButClaimClick')"
							:value="1"
							:disabled="!statshr.ButClaimActive"
						>
							<v-icon color="white">{{contapp.ButClaimOn ? 'mdi-cog' : 'mdi-cog-off'}}</v-icon>
						</v-btn>
					</v-btn-toggle>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
			<v-select
				class="my-2"
				v-model="contapp.fiFPupMde"
				:items="feedFPupMde"
				:label='tag.CptMde'
				v-on:change="handlePupChange('numFPupMde', fiFPupMde)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-2"
				style="height:480px"
			>
				<!-- IP divImg - IBEGIN -->
				<canvas style="display:block;cursor:pointer" ref="cvs" width="640" height="480">This page needs a web-browser capable of displaying canvasses!</canvas>
				<!-- IP divImg - IEND -->
			</div>

			<v-row class="my-2">
				<v-col>
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButPlayClick')"
						:disabled="!statshr.ButPlayActive"
					>
						<v-icon color="white">mdi-play</v-icon>
					</v-btn>
					&#160;
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButStopClick')"
						:disabled="!statshr.ButStopActive"
					>
						<v-icon color="white">mdi-stop</v-icon>
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<v-checkbox
				class="my-2"
				v-model="contiac.ChkAex"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptAex"
				:disabled="!statshr.ChkAexActive"
			/>

			<v-slider
				v-if="statshr.SldExtAvail"
				class="my-2"
				v-model="contiac.SldExt"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptExt"
				:min="statshr.SldExtMin"
				:max="statshr.SldExtMax"
				:disabled="!statshr.SldExtActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldExt"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

			<v-slider
				class="my-2"
				v-model="contiac.SldFcs"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptFcs"
				:min="statshr.SldFcsMin"
				:max="statshr.SldFcsMax"
				:disabled="!statshr.SldFcsActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldFcs"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLlvCamera',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLlvCamera.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - IBEGIN -->
			*/
			refreshLive: function(mask) {
				var cvs = this.$refs.cvs;
				var cvsctx = cvs.getContext("2d");

				var wCvs = cvs.width;
				var hCvs = cvs.height;

				var scale_old = this.scale;

				var whbase = 0;

				var w, h;
				var x0, y0;

				var ix, ix2;

				var i, j, k, l;

				// - scaling
				var d = this.imgdat.data;

				if ( (mask.indexOf("red") != -1) && (mask.indexOf("green") != -1) && (mask.indexOf("blue") != -1) ) {
					whbase = Math.round(Math.sqrt(this.red.length/12));
					if (12*whbase*whbase != this.red.length) return;

				} else if (mask.indexOf("gray") != -1) {
					whbase = Math.round(Math.sqrt(this.gray.length/12));
					if (12*whbase*whbase != this.gray.length) return;
				}

				w = 4 * whbase;
				h = 3 * whbase;

				this.scale = Math.floor(wCvs / w);
				if (Math.floor(hCvs / h) < this.scale) this.scale = Math.floor(hCvs / h);

				if (this.scale != scale_old) for (i = 0; i < 4*hCvs*wCvs; i++) d[i] = 255;

				x0 = wCvs/2 - (this.scale * w) / 2;
				y0 = hCvs/2 - (this.scale * h) / 2;

				// - canvas
				if ( (mask.indexOf("red") != -1) && (mask.indexOf("green") != -1) && (mask.indexOf("blue") != -1) ) {
					for (i = 0; i < h; i++) {
						for (j = 0; j < w; j++) {
							ix = i*w + j;
							ix2 = 4 * ((y0 + this.scale*i)*wCvs + x0 + this.scale*j);

							for (k = 0; k < this.scale; k++) {
								for (l = 0; l < this.scale; l++) {
									d[ix2] = this.red[ix];
									d[ix2+1] = this.green[ix];
									d[ix2+2] = this.blue[ix];
									d[ix2+3] = 255;

									ix2 += 4;
								}

								ix2 += 4 * (wCvs - this.scale);
							}
						}
					}

				} else if (mask.indexOf("gray") != -1) {
					for (i = 0; i < h; i++) {
						for (j = 0; j < w; j++) {
							ix = i*w + j;
							ix2 = 4 * ((y0 + this.scale*i)*wCvs + x0 + this.scale*j);

							for (k = 0; k < this.scale; k++) {
								for (l = 0; l < this.scale; l++) {

									d[ix2] = this.gray[ix];
									d[ix2+1] = this.gray[ix];
									d[ix2+2] = this.gray[ix];
									d[ix2+3] = 255;

									ix2 += 4;
								}

								ix2 += 4 * (wCvs - this.scale);
							}
						}
					}
				}

				cvsctx.putImageData(this.imgdat, 0, 0);
			},
			/*
			<!-- IP cust - IEND -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskLlvCameraDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLlvCamera"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLlvCameraData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLlvCameraData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskLlvCamera) this.contiac = dpcheng.ContIacWzskLlvCamera;
				if (dpcheng.ContInfWzskLlvCamera) this.continf = dpcheng.ContInfWzskLlvCamera;
				if (dpcheng.FeedFPupMde) this.feedFPupMde = dpcheng.FeedFPupMde;
				if (dpcheng.StatShrWzskLlvCamera) this.statshr = dpcheng.StatShrWzskLlvCamera;
				if (dpcheng.TagWzskLlvCamera) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlvCamera);
					this.tag = dpcheng.TagWzskLlvCamera;
				}

				if (dpcheng.ContIacWzskLlvCamera) {
					for (var i = 0; i < this.feedFPupMde.length; i++)
						if (this.feedFPupMde[i].num == this.contiac.numFPupMde) {
							this.contapp.fiFPupMde = this.feedFPupMde[i];
							break;
						}
				}

				if (dpcheng.ContInfWzskLlvCamera) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskLlvCameraData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngLive - RBEGIN -->
				*/
				if (!this.initdone) return;

				if (this.imgdat == null) {
					let cvs = this.$refs.cvs;
					this.imgdat = cvs.getContext("2d").createImageData(cvs.width, cvs.height);
				}

				var mask = [];

				// gray
				if (dpcheng.gray) {
					this.gray = Wzsk.parseUtinyintvec(dpcheng.gray);
					mask.push("gray");
				}

				// RGB
				if (dpcheng.red) {
					this.red = Wzsk.parseUtinyintvec(dpcheng.red);
					mask.push("red");
				}

				if (dpcheng.green) {
					this.green = Wzsk.parseUtinyintvec(dpcheng.green);
					mask.push("green");
				}

				if (dpcheng.blue) {
					this.blue = Wzsk.parseUtinyintvec(dpcheng.blue);
					mask.push("blue");
				}

				this.refreshLive(mask);
				/*
				<!-- IP handleDpchEngLive - REND -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLlvCameraData") this.mergeDpchEngData(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLlvCameraLive") this.handleDpchEngLive(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contapp: {
				fiFPupMde: null,

				ButClaimOn: 0,
			},

			contiac: null,

			continf: null,

			feedFPupMde: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - IBEGIN -->
			*/
			scale: 1.0,
			imgdat: null
			/*
			<!-- IP data.cust - IEND -->
			*/
		})
	}
</script>
