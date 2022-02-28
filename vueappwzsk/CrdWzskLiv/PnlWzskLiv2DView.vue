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
				v-model="contapp.fiFPupPvm"
				:items="FeedFPupPvm"
				:label='tag.CptPvm'
				v-on:change="handlePupChange('numFPupPvm', fiFPupPvm)"
				:disabled="!statshr.PupPvmActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-2"
				style="height:384px"
			>
				<!-- IP divImg - INSERT -->
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
				:label="tag.ChkAex"
				:disabled="!statshr.ChkAexActive"
			/>

			<v-slider
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

			<v-divider/>

			<v-text-field
				class="my-2"
				readonly
				outlined
				v-model="continf.TxtOaf"
				:label="tag.CptOaf"
			/>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButStsClick')"
						:disabled="!statshr.ButStsActive"
					>
						{{tag.ButSts}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-2"
			>
				{{tag.HdgTtb}}
			</h3>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButTccClick')"
					>
						{{tag.ButTcc}}
					</v-btn>
					&#160;
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButTcwClick')"
					>
						{{tag.ButTcw}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-2"
			>
				{{tag.HdgLor}}
			</h3>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButLleClick')"
					>
						{{tag.ButLle}}
					</v-btn>
					&#160;
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButLriClick')"
					>
						{{tag.ButLri}}
					</v-btn>
				</v-col>
			</v-row>

			<div
				class="my-2"
			>
				<!-- IP divLlo - INSERT -->
			</div>

			<div
				class="my-2"
			>
				<!-- IP divLuo - INSERT -->
			</div>

			<div
				class="my-2"
			>
				<!-- IP divLmd - INSERT -->
			</div>

			<v-checkbox
				class="my-2"
				v-model="contiac.ChkLgl"
				v-on:change='updateEng(["contiac"])'
				:label="tag.ChkLgl"
			/>

			<v-checkbox
				class="my-2"
				v-model="contiac.ChkLro"
				v-on:change='updateEng(["contiac"])'
				:label="tag.ChkLro"
			/>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButLtrClick')"
					>
						{{tag.ButLtr}}
					</v-btn>
				</v-col>
			</v-row>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButLclClick')"
					>
						{{tag.ButLcl}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-2"
			>
				{{tag.HdgPos}}
			</h3>

			<div
				class="my-2"
			>
				<!-- IP divPnt - INSERT -->
			</div>

			<v-checkbox
				class="my-2"
				v-model="contiac.ChkPro"
				v-on:change='updateEng(["contiac"])'
				:label="tag.ChkPro"
			/>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButPicClick')"
					>
						{{tag.ButPic}}
					</v-btn>
				</v-col>
			</v-row>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButPclClick')"
					>
						{{tag.ButPcl}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-2"
			>
				{{tag.HdgCld}}
			</h3>

			<v-slider
				class="my-2"
				v-model="contiac.SldCwd"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptCwd"
				:min="statshr.SldCwdMin"
				:max="statshr.SldCwdMax"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldCwd"
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
		name: 'PnlWzskLiv2DView',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLiv2DView.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskLiv2DViewDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLiv2DView"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLiv2DViewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLiv2DViewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacWzskLiv2DView) this.contiac = dpcheng.ContIacWzskLiv2DView;
				if (dpcheng.ContInfWzskLiv2DView) this.continf = dpcheng.ContInfWzskLiv2DView;
				if (dpcheng.feedFPupPvm) this.feedFPupPvm = dpcheng.feedFPupPvm;
				if (dpcheng.StatShrWzskLiv2DView) this.statshr = dpcheng.StatShrWzskLiv2DView;
				if (dpcheng.TagWzskLiv2DView) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLiv2DView);
					this.tag = dpcheng.TagWzskLiv2DView;
				};

				if (dpcheng.ContIacWzskLiv2DView) {
					for (var i = 0; i < this.FeedFPupPvm.length; i++)
						if (this.FeedFPupPvm[i].num == this.contiac.numFPupPvm) {
							this.contapp.fiFPupPvm = this.FeedFPupPvm[i];
							break;
						}
				}

				if (dpcheng.ContInfWzskLiv2DView) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
					if (!this.continf.ButLleOn) this.contapp.ButLleOn = 0;
					else this.contapp.ButLleOn = 1;
					if (!this.continf.ButLriOn) this.contapp.ButLriOn = 0;
					else this.contapp.ButLriOn = 1;
					if (!this.continf.ButLtrOn) this.contapp.ButLtrOn = 0;
					else this.contapp.ButLtrOn = 1;
					if (!this.continf.ButPicOn) this.contapp.ButPicOn = 0;
					else this.contapp.ButPicOn = 1;
					if (!this.continf.ButTccOn) this.contapp.ButTccOn = 0;
					else this.contapp.ButTccOn = 1;
					if (!this.continf.ButTcwOn) this.contapp.ButTcwOn = 0;
					else this.contapp.ButTcwOn = 1;
				}
				/*
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
				if (srefIxWzskVDpch == "DpchEngWzskLiv2DViewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngAlign: function(dpcheng) {
				/*
				<!-- IP handleDpchEngAlign - INSERT -->
				*/
			},

			handleDpchEngLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngLive - INSERT -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLiv2DViewData") this.mergeDpchEngData(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLiv2DViewAlign") this.handleDpchEngAlign(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLiv2DViewLive") this.handleDpchEngLive(obj.dpcheng);
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
				fiFPupPvm: null,

				ButClaimOn: 0,

				ButLleOn: 0,

				ButLriOn: 0,

				ButLtrOn: 0,

				ButPicOn: 0,

				ButTccOn: 0,

				ButTcwOn: 0,
			},

			contiac: null,

			continf: null,

			feedFPupPvm: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
