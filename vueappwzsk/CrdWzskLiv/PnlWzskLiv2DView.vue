<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
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
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<v-select
				class="my-1"
				v-model="contapp.fiFPupPvm"
				:items="feedFPupPvm"
				:label='tag.CptPvm'
				v-on:change="handlePupChange('numFPupPvm', contapp.fiFPupPvm)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-1"
				style="height:384px"
			>
				<!-- IP divImg - INSERT -->
			</div>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButPlayClick')"
						:disabled="!statshr.ButPlayActive"
						fab
						small
						light
						color="primary"
					>
						<v-icon color="white">mdi-play</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('ButStopClick')"
						:disabled="!statshr.ButStopActive"
						fab
						small
						light
						color="primary"
					>
						<v-icon color="white">mdi-stop</v-icon>
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkAex"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptAex"
				:disabled="!statshr.ChkAexActive"
			/>

			<v-slider
				v-if="statshr.SldExtAvail"
				class="my-1"
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
				class="my-1"
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
				v-if="statshr.TxtOafAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtOaf"
				:label="tag.CptOaf"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButStsClick')"
						:disabled="!statshr.ButStsActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButSts}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgTtb}}
			</h3>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButTccClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButTcc}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('ButTcwClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButTcw}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgLor}}
			</h3>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButLleClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButLle}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('ButLriClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButLri}}
					</v-btn>
				</v-col>
			</v-row>

			<div
				v-if="statshr.UpdLloAvail"
				class="my-1"
			>
				<!-- IP divLlo - INSERT -->
			</div>

			<div
				v-if="statshr.UpdLuoAvail"
				class="my-1"
			>
				<!-- IP divLuo - INSERT -->
			</div>

			<div
				v-if="statshr.UpdLmdAvail"
				class="my-1"
			>
				<!-- IP divLmd - INSERT -->
			</div>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkLgl"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptLgl"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkLro"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptLro"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButLtrClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButLtr}}
					</v-btn>
				</v-col>
			</v-row>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButLclClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButLcl}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgPos}}
			</h3>

			<div
				class="my-1"
			>
				<!-- IP divPnt - INSERT -->
			</div>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkPro"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptPro"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButPicClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButPic}}
					</v-btn>
				</v-col>
			</v-row>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButPclClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButPcl}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgCld}}
			</h3>

			<v-slider
				class="my-1"
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
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskLiv2DView) this.contiac = dpcheng.ContIacWzskLiv2DView;
				if (dpcheng.ContInfWzskLiv2DView) this.continf = dpcheng.ContInfWzskLiv2DView;
				if (dpcheng.FeedFPupPvm) this.feedFPupPvm = dpcheng.FeedFPupPvm;
				if (dpcheng.StatShrWzskLiv2DView) this.statshr = dpcheng.StatShrWzskLiv2DView;
				if (dpcheng.TagWzskLiv2DView) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLiv2DView);
					this.tag = dpcheng.TagWzskLiv2DView;
				}
				if (dpcheng.ContIacWzskLiv2DView) {
					for (let i = 0; i < this.feedFPupPvm.length; i++)
						if (this.feedFPupPvm[i].num == this.contiac.numFPupPvm) {
							this.contapp.fiFPupPvm = this.feedFPupPvm[i];
							break;
						}
				}
				if (dpcheng.ContInfWzskLiv2DView) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
					if (!this.continf.ButTccOn) this.contapp.ButTccOn = 0;
					else this.contapp.ButTccOn = 1;
					if (!this.continf.ButTcwOn) this.contapp.ButTcwOn = 0;
					else this.contapp.ButTcwOn = 1;
					if (!this.continf.ButLleOn) this.contapp.ButLleOn = 0;
					else this.contapp.ButLleOn = 1;
					if (!this.continf.ButLriOn) this.contapp.ButLriOn = 0;
					else this.contapp.ButLriOn = 1;
					if (!this.continf.ButLtrOn) this.contapp.ButLtrOn = 0;
					else this.contapp.ButLtrOn = 1;
					if (!this.continf.ButPicOn) this.contapp.ButPicOn = 0;
					else this.contapp.ButPicOn = 1;
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
				if (srefIxWzskVDpch == "DpchEngWzskLiv2DViewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngWzskLiv2DViewAlign: function(dpcheng) {
				/*
				<!-- IP handleDpchEngWzskLiv2DViewAlign - BEGIN -->
				*/
				console.log("PnlWzskLiv2DView.handleDpchEngWzskLiv2DViewAlign()" + dpcheng);
				/*
				<!-- IP handleDpchEngWzskLiv2DViewAlign - END -->
				*/
			},

			handleDpchEngWzskLiv2DViewLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngWzskLiv2DViewLive - BEGIN -->
				*/
				console.log("PnlWzskLiv2DView.handleDpchEngWzskLiv2DViewLive()" + dpcheng);
				/*
				<!-- IP handleDpchEngWzskLiv2DViewLive - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLiv2DViewAlign") this.handleDpchEngWzskLiv2DViewAlign(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLiv2DViewLive") this.handleDpchEngWzskLiv2DViewLive(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLiv2DViewData") this.mergeDpchEngData(obj.dpcheng);
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
			contiac: null,

			continf: null,

			feedFPupPvm: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupPvm: null,

				ButClaimOn: 0,

				ButTccOn: 0,

				ButTcwOn: 0,

				ButLleOn: 0,

				ButLriOn: 0,

				ButLtrOn: 0,

				ButPicOn: 0,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
