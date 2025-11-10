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
			<h3
				class="text-5 my-1"
			>
				{{tag.HdgPvw}}
			</h3>

			<div
				class="my-1"
				style="height:384px"
			>
				<!-- IP divImg - INSERT -->
			</div>

			<v-divider/>

			<div
				class="my-1"
			>
				<!-- IP divNfr - INSERT -->
			</div>

			<v-slider
				class="my-1"
				v-model="contiac.SldFst"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptFst"
				:min="statshr.SldFstMin"
				:max="statshr.SldFstMax"
				:disabled="!statshr.SldFstActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldFst"
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
				v-model="contiac.SldFsp"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptFsp"
				:min="statshr.SldFspMin"
				:max="statshr.SldFspMax"
				:disabled="!statshr.SldFspActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldFsp"
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
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSte"
				:label="tag.CptSte"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButStaClick')"
						:disabled="!statshr.ButStaActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButSta}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('ButStoClick')"
						:disabled="!statshr.ButStoActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButSto}}
					</v-btn>
				</v-col>
			</v-row>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskHwcConfig',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskHwcConfig.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzskHwcConfigDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskHwcConfig"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskHwcConfigData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskHwcConfigData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskHwcConfig) this.contiac = dpcheng.ContIacWzskHwcConfig;
				if (dpcheng.ContInfWzskHwcConfig) this.continf = dpcheng.ContInfWzskHwcConfig;
				if (dpcheng.FeedFRbuMde) this.feedFRbuMde = dpcheng.FeedFRbuMde;
				if (dpcheng.StatShrWzskHwcConfig) this.statshr = dpcheng.StatShrWzskHwcConfig;
				if (dpcheng.TagWzskHwcConfig) {
					Wzsk.unescapeBlock(dpcheng.TagWzskHwcConfig);
					this.tag = dpcheng.TagWzskHwcConfig;
				}
				if (dpcheng.ContInfWzskHwcConfig) {
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
				if (srefIxWzskVDpch == "DpchEngWzskHwcConfigData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngWzskHwcConfigAlign: function(dpcheng) {
				/*
				<!-- IP handleDpchEngWzskHwcConfigAlign - BEGIN -->
				*/
				console.log("PnlWzskHwcConfig.handleDpchEngWzskHwcConfigAlign()" + dpcheng);
				/*
				<!-- IP handleDpchEngWzskHwcConfigAlign - END -->
				*/
			},

			handleDpchEngWzskHwcConfigLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngWzskHwcConfigLive - BEGIN -->
				*/
				console.log("PnlWzskHwcConfig.handleDpchEngWzskHwcConfigLive()" + dpcheng);
				/*
				<!-- IP handleDpchEngWzskHwcConfigLive - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskHwcConfigData") this.mergeDpchEngData(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskHwcConfigAlign") this.handleDpchEngWzskHwcConfigAlign(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskHwcConfigLive") this.handleDpchEngWzskHwcConfigLive(obj.dpcheng);
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

			feedFRbuMde: null,

			statshr: null,

			tag: null,

			contapp: {
				ButClaimOn: 0,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
